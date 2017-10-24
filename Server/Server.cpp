// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"





int main()
{
	cServer* server = new cServer();
	server->port = 3487;
	server->startServer();
	
    return 0;
}

