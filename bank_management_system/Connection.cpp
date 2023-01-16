#include "Connection.h"
#include "sqlite3.h"
#include <iostream>
#include "Customer.h"
#include <stdio.h>



using namespace std;

// argc = number of results, azColName = each returned column, argv = the value of item
int callback(void* Not_used, int argc, char** arvg, char** azColName) {
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << arvg[i] << endl;
	}
	return 0;
}

Connection::Connection() {
	
	sqlite3* db = nullptr;							// Pointer for the sqlite3 object db
	const char* db_location = "./bank.db";
	char *err_msg = 0;							// variable to hold any error msg
	char* sql = nullptr;	

	// The statement compiled pointer
	sqlite3_stmt* stmt = nullptr;
	//open_db();
}
int Connection::check_db_errors(int p_rc) {
	if (p_rc != SQLITE_OK) {
		// Show an error message
		cout << "DB Error: " << sqlite3_errmsg(db) << endl;
		cout << "Connection not successful" << endl;
		// Close the connection
		sqlite3_close(db);
		// Return an error
		return 1;
	}
	else {

		cout << "Connection successful!" << endl;
		return 0;
	}
}
// compile sql statement to binary
void Connection::prep_sql(string a_sql) {
	if (sqlite3_prepare_v2(db, a_sql.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
		printf("ERROR: while compiling sql: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		sqlite3_finalize(stmt);
	}
	else {
		// execute sql statement, and while there are rows returned, print ID
		int ret_code = 0;
		while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
			printf("TEST: ID = %d\n", sqlite3_column_int(stmt, 0));
		}
		if (ret_code != SQLITE_DONE) {
			//this error handling could be done better, but it works
			printf("ERROR: while performing sql: %s\n", sqlite3_errmsg(db));
			printf("ret_code = %d\n", ret_code);
		}

		//release resources
		sqlite3_finalize(stmt);
		sqlite3_close(db);
	}
}

void Connection::transaction_v2(string a_sql) {
	try
	{
		int exit = 0;
		exit = sqlite3_open(db_location, &db);
		check_db_errors(rc);
		//string instructions = "ALTER TABLE " + string(a_sql) +" \
		//					   RENAME COLUMN cust_account_number TO cust_id;";
		//cout << instructions << endl;
		exit = sqlite3_exec(db, a_sql.c_str(), NULL, 0, &err_msg);
		if (exit != SQLITE_OK) {
			cerr << "Error in transaction: " << err_msg << endl;
			sqlite3_free(err_msg);
			prep_sql(a_sql);
		}
		else {
			prep_sql(a_sql);
			cout << "Transaction completed Successfully" << endl;
		}
			
		sqlite3_close(db);
	}
	catch (const exception& e) {
		cerr << e.what();
	}
}

void Connection::transaction(string a_sql) {
	try
	{
		int exit = 0;
		exit = sqlite3_open(db_location, &db);
		check_db_errors(rc);
		//string instructions = "ALTER TABLE " + string(a_sql) +" \
		//					   RENAME COLUMN cust_account_number TO cust_id;";
		//cout << instructions << endl;
		exit = sqlite3_exec(db, a_sql.c_str(), NULL, 0, &err_msg);
		if (exit != SQLITE_OK) {
			cerr << "Error in transaction: " << err_msg<< endl;
			sqlite3_free(err_msg);
		}
		else
			cout << "Transaction completed Successfully" << endl;
		sqlite3_close(db);
	}
	catch (const exception& e) {
		cerr << e.what(); 
	}
}

void Connection::add_cust_to_db(Customer &cust) {
	int rc = sqlite3_open(db_location, &db);
	int id = cust.get_cust_id();
	check_db_errors(rc);
	string d = std::to_string(cust.get_cust_id());
	string instructions = "INSERT INTO CUSTOMERS (cust_id,cust_first_name,cust_last_name)\
		VALUES(" + d + ", '" + cust.get_cust_fname() + "', '" + cust.get_cust_lname() + "'); ";
	cout << instructions << endl;
	rc = sqlite3_exec(db, instructions.c_str(), NULL, 0, &err_msg);
	sqlite3_close(db);
}








