// Simple_MySQL_Connect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mysql_connection.h>

#include <cppconn\driver.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <cppconn\exception.h>

int main()
{
	sql::Driver *driver;
	sql::Connection *conn;
	sql::Statement *stmt;
	sql::ResultSet *res;

	driver = get_driver_instance();
	conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");
	conn->setSchema("test");
    return 0;
}

