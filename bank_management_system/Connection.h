#pragma once
#include "sqlite3.h"
#include "Customer.h"

using namespace std;

class Connection {
private:
	sqlite3* db;
	const char* db_location = "./bank_data.db";
	char* err_msg;
	int rc;
	//const char* sql;
	sqlite3_stmt* stmt;

	// argc = number of results, azColName = each returned column, argv = the value of item
public:
	Connection();
	int check_db_errors(int);
	sqlite3 open_db();
	void transaction(string a_sql);
	void add_cust_to_db(Customer &cust);
	int callback(void* Not_used, int argc, char** arvg, char** azColName);
};