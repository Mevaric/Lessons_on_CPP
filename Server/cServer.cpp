#include "stdafx.h"

cServer::cServer() {}
cServer::~cServer() {}
void cServer::startServer() {
	SOCKADDR_IN serverAddr;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0)
		std::cout << "WSASStartup is OK" << std::endl;
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_family = AF_INET;
	this_s = socket(AF_INET, SOCK_STREAM, NULL);
	if (this_s == SOCKET_ERROR)
		std::cout << "SOCKET_ERROR: socket not created" << std::endl;

	if (bind(this_s, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != SOCKET_ERROR)
		std::cout << "SOCKET_ERROR: socket not binded" << std::endl;

	if (listen(this_s, SOMAXCONN) != SOCKET_ERROR)
		std::cout << "SOCKET_ERROR: socket can't start listenin at port" << std::endl;
	handle();
}
void cServer::closeServer() {
	closesocket(this_s);
	WSACleanup();
	std::cout << "Server was stoped" << std::endl;
}
void cServer::handle() {
	while (true) {
		SOCKET accept_s;
		SOCKADDR_IN clientAddr;
		int addrlen = sizeof(clientAddr);
		if ((accept_s = accept(this_s, (struct sockaddr*)&clientAddr, &addrlen)) != 0) {
			std::cout << "send\n";
			printf("sended Client connected from 0  %u.%u.%u.%u:%u\n",
				(unsigned char)clientAddr.sin_addr.S_un.S_un_b.s_b1,
				(unsigned char)clientAddr.sin_addr.S_un.S_un_b.s_b2,
				(unsigned char)clientAddr.sin_addr.S_un.S_un_b.s_b3,
				(unsigned char)clientAddr.sin_addr.S_un.S_un_b.s_b4,
				ntohs(clientAddr.sin_port));
			cClient* client = new cClient(accept_s, clientAddr);
		}
		Sleep(200);
	}
}