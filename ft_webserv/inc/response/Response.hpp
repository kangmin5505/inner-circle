#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <cstdio>
# include <sstream>
# include <dirent.h>
# include <sys/stat.h>
# include <ctime>

# include "Cgi.hpp"
# include "File.hpp"
# include "../http.hpp"
# include "../parse/Util.hpp"
# include <errno.h>

extern int errno;

//# include "../http.hpp"

extern Config g_conf;

struct ResponseStartLine
{
	string	protocol;		// HTTP 버전 (HTTP/1.1)
	int		statusCode;		// 상태 코드 (200, 404)
	string	reasonPhrase;	// 사유 구절
};

struct Response
{
	Request *Req;
	ResponseStartLine StartLine;
	map<string, string> Header;
	string Body;

	string* Html;

	string confName;
	string locName;
	string postBody;
	int contentLength;
	int statement;
	int progress;

	/**
	 * brief : 파일 경로 관련 변수
	 */
	Contents *contentResult;
	string	url;
	string	root;
	string	upload;
	string	fileName;
	string	ext;
	string	path;
	string	excutor;
	vector<string> params;

	bool cgiFlag;

	Response();

	Response(const Request & req);

	~Response();

	string toHtml()
	{
		string ret;

		ret += StartLine.protocol + ' ' + Util::to_string(StartLine.statusCode) + ' ' + StartLine.reasonPhrase + "\r\n";
		for (std::map<string, string>::iterator it = Header.begin(); it != Header.end(); ++it)
			ret += it->first + ": " + it->second + "\r\n";
		ret += "\r\n";
		if (!Body.empty())
			ret += Body + "\r\n";
		return ret;
	}
	void clear();

	int set(const std::string& configName, int error_code)
	{
		this->confName = configName;
		StartLine.statusCode = error_code;
		return make_errorpage(error_code);
	}

	int set(const Request& req);
	int redirect(int code, const string& location);
	int execute();
	int write();
	int read();
	int send(int clientFd);

	/**
	 * @brief : exec -> read or write로 진행 예정
	 * @return exec : WRITE or READ or DONE
	 * @return write : WRITE or READ
	 * @return read : READ or DONE
	 */

	int makeHeader();
	int makeStartLine();
	int make_errorpage(int code);
	std::string findExtension(const std::string& url);
	std::string findFileName(const std::string& url);
	int listing(string path, string head);
	std::string string_to_lower(std::string s);
};

Response::Response()
: Html(0), contentResult(0)
{}
Response::~Response()
{
	clear();
}

int Response::makeHeader()
{
	Header["date"] = Util::get_date();
	Header["server"] = "miniNginx/1.1";

	if (!excutor.empty())
	{
		std::vector<string> header = Util::split(Body, '\n');

		std::string::size_type cgiHeaderEnd = Body.find("\r\n\r\n");
		int tmp = 4;
		if (cgiHeaderEnd == std::string::npos)
		{
			cgiHeaderEnd = Body.find("\n\n");
			tmp = 2;
		}
		for (std::vector<string>::iterator it = header.begin(); it != header.end(); ++it)
		{
			Util::remove_crlf(*it);

			if ((*it).empty())
				break ;
			std::string::size_type colon = (*it).find(": ");
			std::string key = (*it).substr(0, colon);
			std::string value = (*it).substr(colon + tmp/2);
			key = string_to_lower(key);
			Header[key] = value;	
		}
		Body.erase(0, cgiHeaderEnd + tmp);
	}
	if (StartLine.statusCode / 100 == 2 && Req->Header["connection"] != "close")
		Header["connection"] = "keep-alive";
	else
		Header["connection"] = "close";	

	map<string, string>::iterator it;
	if (!(StartLine.statusCode == 204 || StartLine.statusCode == 304))
	{
		Header["content-length"] = Util::to_string(Body.size());
		it = Header.find("content-type");
		if (it == Header.end())
			Header["content-type"] = g_conf.getContentType(ext);
	}
	else
		Header["connection"] = "close";
	return makeStartLine();
}

std::string Response::string_to_lower(std::string s)
{
	for (size_t i = 0; i < s.size(); ++i)
		s[i] = std::tolower(s[i]);
	return s;
}



/**
 * @brief set & return nextToDo
 * @return statement
 */
int 	Response::execute()
{
	/**
	 * @brief try remove file, throw error if catch error 
	 */

	try
	{
		if (Req->StartLine.method != "GET"
		&& Req->StartLine.method != "POST"
		&& Req->StartLine.method != "DELETE")
			throw 400;
		if (Req->StartLine.method == "DELETE")
		{
			if (remove(path.c_str()))
				throw 404;
			Body = url;
			return 	makeHeader();
		}

		//	Method Error -> Bad Request
		if (g_conf[confName][locName].is_exist("return"))
			return redirect(
					StartLine.statusCode = Util::stoi(g_conf[confName][locName]["return"][0]),
					g_conf[confName][locName]["return"][1]);
		if (Req->StartLine.method != "GET" && Req->StartLine.method != "POST")
			throw 400;
		if (g_conf[confName][locName].is_exist(ext))
		{
			std::map<string, string> ReqHeader = Req->Header;
			ReqHeader["REMOTE_ADDR"] = Req->ip;
			ReqHeader["REQUEST_METHOD"] = Req->StartLine.method;
			ReqHeader["PATH_TRANSLATED"] = path;
			ReqHeader["SCRIPT_NAME"] = Req->virtualPath;

			excutor = g_conf[confName][locName][ext][0];
			cgiFlag = true;
			contentResult = new Cgi(path, excutor, ReqHeader);
		}
		else
		{
			if (Req->StartLine.method == "GET")
				contentResult = new File(path, O_WRONLY);
			else
				contentResult = new File(path, O_WRONLY | O_TRUNC);
		}
		progress = contentResult->set();
		if (Req->StartLine.method == "GET" && contentResult->checkNull())
			return statement = READ_RESPONSE;
		if (Req->StartLine.method == "POST")
			return statement = WRITE_RESPONSE;
	}
	catch (int errNo)	//	예외 발생 시 일단 객체 내에서 처리 -> 수정 O
	{
		return make_errorpage(StartLine.statusCode = errNo);
	}
	return makeHeader();
}

/**
 * @brief Write & return nextToDo
 * @return statement
 */
int 	Response::write()
{
	if (postBody.empty())
		return READ_RESPONSE;

	//	쓰고 쓸 것이 남아있으면 WRITE_RESPONSE 반환
	size_t	len = ::write(contentResult->inFd, postBody.c_str(), postBody.size());

	if (len < 0)
		throw StartLine.statusCode = 500;

	if (len == postBody.size())
	{
		postBody.erase(0, len);
		close(contentResult->inFd);
		return READ_RESPONSE;
	}

	postBody.erase(0, len);
	//	전부 보냈으면 결과 값 받아오기 위해 READ_RESPONSE 반환
	if (len < postBody.size())
		return READ_RESPONSE;

	return WRITE_RESPONSE;
}

/**
 * @brief Read & return nextToDo
 * @return statement
 */
int 	Response::read()
{
	//	읽고 읽을것이 남아있으면 READ_RESPONSE 반환
	char buf[BUFFER_SIZE];
	memset(buf, 0, BUFFER_SIZE);
	ssize_t	len = ::read(contentResult->outFd, buf, BUFFER_SIZE);
	Body += string(buf, len);

	if (len < 0)
		throw StartLine.statusCode = 500;

	if (len < BUFFER_SIZE && !cgiFlag)
		return makeHeader();

	return READ_RESPONSE;
}

int Response::redirect(int code, const string& location)
{
	Header["location"] = location;
	StartLine.statusCode = code;
	StartLine.reasonPhrase = g_conf.getStatusMsg(code);
	return makeHeader();
}

int Response::send(int clientFd)
{
	if (!Html)
		Html = new string(toHtml());

	size_t bufSize = Html->size();

	ssize_t	len = ::send(clientFd, Html->c_str(), bufSize, 0);

	if (len > 0)
		Html->erase(0, len);

	if (len < 0)
	{
		Header["connection"] = "close";
		return END_RESPONSE;
	}
		
	if (Html->empty())
	{
		delete Html;Html = 0;
		return END_RESPONSE;
	}

	if (!len && !Html->empty())
		throw 500;
	
	return SEND_RESPONSE;
}

std::string Response::findExtension(const std::string& url)
{
	std::string::size_type pos = url.rfind('.');
	if (pos == std::string::npos)
		return "";
	return std::string(url.begin() + pos, url.end());
}

std::string Response::findFileName(const std::string& url)
{
	std::string::size_type pos = url.rfind('/');
	if (pos == std::string::npos)
		return "";
	return std::string(url.begin() + pos + 1, url.end());
}

int Response::make_errorpage(int code)
{
	if (code == 204 || code == 304)
	{
		return makeHeader();
	}
	ext = ".html";
	if (g_conf[confName].is_exist(locName))
		if (g_conf[confName][locName].is_exist("error_page"))
		{
		for (size_t i = 0; i < g_conf[confName][locName]["error_page"].size() - 1; ++i)
			if (Util::to_string(StartLine.statusCode) == g_conf[confName][locName]["error_page"][i])
			{	
				url = g_conf[confName][locName]["error_page"][g_conf[confName][locName]["error_page"].size() - 1];
				return execute();
			}
		}
	Body =
			"<!DOCTYPE html>\n"
			"<html>\n"
			"  <h1>\n"
			"    " + Util::to_string(StartLine.statusCode) + "\n"
															 "  </h1>\n"
															 "</html>\n";
	Header["content-type"] = "text/html";
	return makeHeader();
}

int Response::listing(string path, string head)
{
	string ret;
	string page;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path.c_str())))
	{
		while ((ent = readdir(dir)))
		{
			struct stat statbuf;
			std::string tmp = ent->d_name;
			std::string checker = path + tmp;
			stat(checker.c_str(), &statbuf);
			if (S_ISDIR(statbuf.st_mode))
				tmp += "/" ;
			page += "<a href=\"" + tmp + "\">" + tmp + "</a>\n";
		}
		closedir (dir);
	}

	Body =
			"<html>\n"
			"<head><title>Index of " + head + " </title></head>\n"
											  "<body>\n"
											  "<h1>Index of " + head + " </h1><hr><pre>\n" +
			page +
			"</pre><hr></body>\n"
			"</html>\n";
	Header["content-type"] = "text/html";
	return makeHeader();
}

int Response::makeStartLine()
{
	StartLine.reasonPhrase = g_conf.getStatusMsg(StartLine.statusCode);
	StartLine.protocol = "HTTP/1.1";
	return statement = SEND_RESPONSE;
}

void Response::clear()
{
	//	내부 객체 delete -> REPEAT REQUEST 반환 -> new Req로 연결(Req 삭제위치)
	delete contentResult;
	delete Html;
	contentResult = 0;
	Html = 0;
}

int Response::set(const Request& req)
{
	StartLine.statusCode = 200;
	Req = const_cast<Request*>(&req);
	url = req.virtualPath;
	confName = req.configName;
	locName = req.locationName;
	postBody = req.bodySS.str();
	fileName = req.fileName;
	cgiFlag = false;

	//	root 설정
	char*	tmp = getcwd(0, 0);
	path = tmp;
	free(tmp);
	try
	{
		//	Redirect Uri
		if (g_conf[confName][locName].is_exist("return"))
			return redirect(
					StartLine.statusCode = Util::stoi(g_conf[confName][locName]["return"][0]),
					g_conf[confName][locName]["return"][1]);
		//	Root Directory
		if (g_conf[confName][locName].is_exist("root"))
			path = Util::join(path, g_conf[confName][locName]["root"].front(), '/');
		if (g_conf[confName][locName].is_exist("limit_except"))
			for (vector<string>::const_iterator it = g_conf[confName][locName]["limit_except"].begin();
				 it != g_conf[confName][locName]["limit_except"].end(); ++it)
				if (*it == Req->StartLine.method)
					throw 405;
		//	Upload Path
		//	Uri Check Dir is or not
		if (req.StartLine.method == "POST" && g_conf[confName][locName].is_exist("upload"))
			path = Util::join(path, g_conf[confName][locName]["upload"][0], '/');
		if (!fileName.empty())
			path = Util::join(path, fileName, '/');
		if (req.StartLine.method == "GET" && Util::is_dir(path))
		{
			if (g_conf[confName][locName].is_exist("index"))
				path = Util::join(path, g_conf[confName][locName]["index"][0], '/');
			else if (*req.StartLine.url.rbegin() != '/')
				return redirect(301, req.StartLine.url + '/');
			else if (g_conf[confName][locName].is_exist("autoindex") && g_conf[confName][locName]["autoindex"][0] == "on")
				return listing(path, url);
			else
				throw 403;
			Util::is_dir(path);
		}
		//	get Extension
		ext = findExtension(path);
	}
	catch (int errNo)
	{
		return make_errorpage(StartLine.statusCode = errNo);
	}
	return statement = execute();
}

#endif