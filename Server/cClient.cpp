#include "stdafx.h"
cClient::cClient(SOCKET s, SOCKADDR_IN sock_in) {
	c_sock = s;
	c_addr = sock_in;
	std::cout << "Client created";
	handle();
}
cClient::~cClient() {}
void cClient::handle() {
	while(true) {
		int k = recv(c_sock, buffer, sizeof(buffer), NULL);
		if (k>0) {
			printf(buffer);
		}
		Sleep(30);
	}
}