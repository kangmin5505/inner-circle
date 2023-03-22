#ifndef CLIENTSOCKET_HPP
# define CLIENTSOCKET_HPP


# include <arpa/inet.h>

# include "Type.hpp"
# include "../request/Request.hpp"
# include "../response/Response.hpp"
# include "Socket.hpp"


class ClientSocket
	: public Socket
{
public:
	bool is_expired();
	void update_lastEventTime();
	void update_state(State s);
	State set_response(const Request& req);
	State set_response(int error_code);
	void set_readFD(FD fd);
	void set_writeFD(FD fd);
	void set_PID(PID pid);
	FD get_readFD() const;
	FD get_writeFD() const;
	PID get_PID() const;
	Request* get_request() const;
	Response* get_response() const;
	const std::string& get_server_ip_port() const;
	State get_state() const;
	void reset();

	ClientSocket(FD clientFD, const SockAddr& addr, const std::string& serverIPPort_);
	~ClientSocket();

private:
	ClientSocket();
	ClientSocket(const ClientSocket& other);
	ClientSocket operator=(const ClientSocket& rhs);

	Time get_current_time() const;

private:
	Time lastEventTime;
	std::string serverIPPort;
	Request* req;
	Response* res;
	FD readFD;
	FD writeFD;
	PID childPID;
	State state;
};

// ClientSocket implementation

bool ClientSocket::is_expired()
{
	bool expired = (get_current_time() - lastEventTime >= TIMEOUT);
	if (expired)
		return true;
	lastEventTime = get_current_time();
	return false;
}

void ClientSocket::update_lastEventTime()
{
	lastEventTime = get_current_time();
}

void ClientSocket::update_state(State s)
{
	state = s;
}
State ClientSocket::set_response(const Request& req)
{
	return res->set(req);
}

State ClientSocket::set_response(int error_code)
{
	return res->set(req->configName, error_code);
}

void ClientSocket::set_readFD(FD fd)
{
	readFD = fd;
}

void ClientSocket::set_writeFD(FD fd)
{
	writeFD = fd;
}

void ClientSocket::set_PID(PID pid)
{
	childPID = pid;
}

FD ClientSocket::get_readFD() const 
{
	return readFD;
}

FD ClientSocket::get_writeFD() const
{
	return writeFD;
}

PID ClientSocket::get_PID() const
{
	return childPID;
}

Request* ClientSocket::get_request() const
{
	return req;
}

Response* ClientSocket::get_response() const
{
	return res;
}

const std::string& ClientSocket::get_server_ip_port() const
{
	return serverIPPort;
}

State ClientSocket::get_state() const
{
	return state;
}

void ClientSocket::reset()
{
	delete req;
	delete res;
	req = new Request(fd, serverIPPort);
	res = new Response();
	set_readFD(0);
	set_writeFD(0);
	set_PID(0);
}


// private
ClientSocket::ClientSocket()
{}

ClientSocket::ClientSocket(FD clientFD, const SockAddr& addr, const std::string& serverIPPort_)
	: lastEventTime(get_current_time()), serverIPPort(serverIPPort_), 
		req(0), res(new Response()), readFD(0), writeFD(0), childPID(0), state(READ_REQUEST)
{
	fd = clientFD;
	ip = inet_ntoa(addr.sin_addr);
	port = "";
	type = CLIENT;
	req = new Request(fd, serverIPPort);
	req->ip = ip;
}

ClientSocket::~ClientSocket()
{
	delete req;
	delete res;
	req = 0;
	res = 0;
}

//private
ClientSocket::ClientSocket(const ClientSocket& other)
{
	(void)other;
}

//private
ClientSocket ClientSocket::operator=(const ClientSocket& rhs)
{
	(void)rhs;
	return *this;
}

Time ClientSocket::get_current_time() const
{
	return time(NULL);
}

#endif // CLIENTSOCKET_HPP