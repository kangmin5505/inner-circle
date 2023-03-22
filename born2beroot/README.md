# 42seoul-Born2beRoot
Summary: This document is a System Administration related exercise

## Introduction
This project aims to introduce you to the wonderful world of virtualization.\
\
You will create your first machine in VirtualBox (or UTM if you can't use VirtualBox)
under specific instructions.\
Then, at the end of this project, you will be able to set up
your own operating system while implementing strict rules.

## General guidelines
The use of <b>VirtualBox</b> (or <b>UTM</b> if you can't use <b>VirtualBox</b>) is mandatory.\
\
You only have to turn in a <b>signature.txt</b> file at the root of your repository.\
You must paste in it the signature of your machine's virtual disk.\
Go to Submission and peer-evaluation ofr more information.

## Mandatory part
![image](https://user-images.githubusercontent.com/74703501/145704037-c795db02-e153-449c-a3db-e93f1d73ccf2.png)\
\
You must choose as an operating system either the latest stable version of <b>Debian</b> (no testing/unstable), or the latest stable version of <b>CentOS</b>.\
<b>Debian</b> is highly recommended if you are new to system administration.\
\
![image](https://user-images.githubusercontent.com/74703501/145704170-56b59b0b-aeec-4470-932e-ca9271d86d4e.png)\
\
You must create at least 2 encrypted partitions using <b>LVM</b>.\
Below is an example of the expected partitioning:\
\
![image](https://user-images.githubusercontent.com/74703501/145705899-1bc606f8-6c1b-4df6-8780-99eb676e2108.png)\
\
![image](https://user-images.githubusercontent.com/74703501/145704312-aaaf094d-825c-40aa-bda0-d9081c81961f.png)\
\
A <b>SSH</b> service will be running on port 4242 only.\
For security reasons, it must not be possible to connect using <b>SSH</b> as root.\
\
![image](https://user-images.githubusercontent.com/74703501/145704368-17f895cd-d898-48ae-896c-e2f48b635236.png)\
\
You have to configure your operating system with the <b>UFW</b> firewall and thus leave only port 4242 open.\
\
![image](https://user-images.githubusercontent.com/74703501/145704419-bc84fccc-5efc-48c1-aeab-c18d86bbbf76.png)

- The <b>hostname</b> of your virtual machine must be your login ending with 42 (e.g., whi42). \
You will have to modify this hostname during your evaluation.
- You have to implement a strong password policy.
- You have to install and configure <b>sudo</b> following strict rules.
- In addition to the root user, a user with your login as username has to be present.
- This user has to belong to the <b>user42</b> and <b>sudo</b> groups.\
\
![image](https://user-images.githubusercontent.com/74703501/145704565-cd4bbcfb-7663-4207-80c9-4616efe0010f.png)\
\
To set up a strong password policy, you have to comply with the following requirements:

- Your password has to expire every 30 days.
- The minimum number of days allowed before the modification of a password will be set to 2.
- The user has to receive a warning message 7 days before their password expires.
- Your password must be at least 10 characters long.\
It must contain an uppercase letter and a number.\
Also, it must not contain more than 3 consecutive identical characters.
- The password must not include the name of the user.
- The following rule does not apply to the root password:\
The password must have at least 7 characters that are not part of the former password.
- Of course, your root password has to comply with this policy.\
\
![image](https://user-images.githubusercontent.com/74703501/145704745-ebbd0417-8d57-4f62-ad97-af0ec6df0ea1.png)\
\
To set up a strong configuration for your <b>sudo</b> group, you have to comply with the following requirements:
- Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
- A custom message of your choice has to be displyed if an error due to a wrong password occurs when using <b>sudo</b>.
- Each action using <b>sudo</b> has to be archived, both inputs and outputs.\
The log file has to be saved in the /var/log/sudo/ folder.
- The TTY mode has to be enabled for security reasons.
- For security reasons too, the paths that can be used by <b>sudo</b> must be restricted.\
Example:\
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

Finally, you have to create a simple script called <b>monitoring.sh</b>.\
It must be developed in bash.\
\
At server startup, the script will disply some information (listed below) on all terminals every 10 minutes (take a look at <b>wall</b>).\
The banner is optional.\
No error must be visible.\
\
Your script must always be able to disply the following information:
- The architecture of your operating system and its kernel version.
- The number of physical processors.
- The number of virtual processors.
- The current available RAM on your server and its utilization rate as a percentage.
- The current available memory on your server and its utilization rate as a percentage.
- The current utilization rate of your processors as a percentage.
- The date and time of the last reboot.
- Whether LVM is active or not.
- The number of active connections.
- THe number of users using the server.
- The IPv4 address of your server and its MAC (Media Access Control) address.
- The number of commands executed with the sudo program.\
\
![image](https://user-images.githubusercontent.com/74703501/145705368-e38e1455-112b-46c2-b8eb-1dca589a979f.png)\
\
This is an example of how the script is expected to work:\
\
![image](https://user-images.githubusercontent.com/74703501/145705397-43f59175-7e26-4d11-b332-8032599e7337.png)\
\
Below are two commands you can use to check some of the subject's requirements:\
For <b>Debian</b>:\
\
![image](https://user-images.githubusercontent.com/74703501/145705444-78de50f3-be47-4c34-977d-a067a17b0197.png)
## Bonus part
Bonus list:
- Set up partitions correctly so you get a structure similar to the one below:\
\
![image](https://user-images.githubusercontent.com/74703501/145705468-421b623b-0786-4b2e-a4aa-2cb1b44b18ed.png)
- Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.
- Set up a service of your choice that you think is useful (NGINX / Apache2 excluded!).\
During the defense, you will have to justify your choice.\
\
![image](https://user-images.githubusercontent.com/74703501/145705521-c332fcc2-f313-409c-bd92-6ddffb8dd833.png)

## SUbmission and peer-evaluation
You only have to turn in a <b>signature.txt</b> file at the root of your <b>Git</b> repository.\
You must paste in it the signature of your machine's virtual disk.\
To get this signature, you first have to open the default installation folder (it is the folder where your VMs are saved):
- Windows: %HOMEDRIVE%%HOMEPATH$\\VirtualBox VMs\\
- Linux: ~/VirtualBox VMs/
- MacM1: ~/Library/Containers/com.utmapp.UTM/Data/Documents/
- MacOS: ~/VirtualBox VMs/

Then, retrieve the signature from the ".vdi" file (or ".qcow2 for UTM'users) of your virtual macine in sha1 format.\
Below are 4 command examples for a centos_serv.vdi file:

- Windows: certUtil -hashfile centos_serv.vdi sha1
- Linux: sha1sum centos_serv.vdi
- MacM1 : shasum Centos.utm/Images/disk-0.qcow2
- MacOS : shasum centos_serv.vdi

This is an example of what kind of output you will get:
- 6e657c4619944be17df3c31faa030c25e43e40af\
\
![image](https://user-images.githubusercontent.com/74703501/145705841-983b1be7-7b12-4edc-9fd1-525043dbfdab.png)\
\
![image](https://user-images.githubusercontent.com/74703501/145705853-daeb105b-6bd9-4437-ae13-b8cc3e56b3ba.png)

## 해결과정
1. [가상환경 구축(bonus 버전)](https://velog.io/@appti/born2beroot-Virtualbox-Debian-%EC%84%A4%EC%B9%98)
2. [sudo 및 sudoers](https://parkseunghan.notion.site/sudo-790c926b0f5644738318549e9f176a70)
3. [AppArmor 설정](https://parkseunghan.notion.site/Vim-Apparmor-22792a48e9d2490680a7ddcb25a79ded)
4. [UFW 설정](https://parkseunghan.notion.site/UFW-58c8e4a34bb64a75b453ee9fefedd3be)
5. [Port 및 SSH 설정](https://parkseunghan.notion.site/SSH-SSH-bc716b8f40604d45a013ad4f169984c2)
6. [비밀번호 정책 설정](https://parkseunghan.notion.site/91f7d40e6a10470d97917677b214bab8)
7. [monitoring.sh](https://infinitt.tistory.com/390)
8. [WordPress](https://nostressdev.tistory.com/11)
    - [php 설치](https://ksbgenius.github.io/wordpress/2020/08/15/wordpress-installation-part2-php-fpm-install-and-configure.html)

## What I Learned
- 가상환경 구축
- LVM
- 보안 설정
- 유저, 그룹 관리
- 쉘스크립트
- wordpress website 연결
> Born2beroot는 어려웠지만, 많은 것을 배울 수 있는 과제였다.
> 왜냐하면 지금까지 들어보지 못 한 가상환경 구축이나 LVM, apparmor 등등의 개념이 나와서 공부해야 될 것이 많았기 때문이다.
> 그렇지만, 하나씩 개념을 익히다보니 전체적인 흐름이 그려졌고, 결국 이 과제를 끝을 냈다.
> 공부한 것 중에 가장 기억에 남는 내용은 LVM이다.
> LVM은 Logical Volume Manager의 약자로, 하드웨어를 유동적으로 사용할 수 있도록 도와준다.
> LVM이 가장 기억에 남는 이유는 물리적인 실체를 논리적으로 변경하여 원하는 크기로 사용하는 방법이 정말 획기적이라고 생각했기 때문이다.
> 이 과제를 하며 인터넷 검색으로는 전반적인 개념이 제대로 잡히지 않아서 '이것이 우분투 리눅스다' 라는 책을 사서 공부했는데, 정말 도움이 많이 되었다.
> 다음 과제부터도 인터넷뿐만 아니라 여러가지 개념들을 이해하기 쉽게 설명한 책도 같이 보며 공부해야겠다.
