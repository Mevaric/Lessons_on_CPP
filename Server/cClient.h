#pragma once
class cClient
{
public:
	cClient(SOCKET s, SOCKADDR_IN sock_in);
	~cClient();
	void handle();
private:
	SOCKET c_sock;
	SOCKADDR_IN c_addr;
	char buffer[1024];
};
