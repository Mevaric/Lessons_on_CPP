#pragma once
class cServer {
public:
	cServer();
	~cServer();
	void startServer();
	void closeServer();
	void handle();
	unsigned short port;
private:
	SOCKET this_s;
	WSADATA wsaData;

};