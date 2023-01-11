#include "Customer.h"
#include <iostream>
#include <string>
#include "Connection.h"
using namespace std;

static int number_of_customers = 0;

// default constructor
Customer::Customer() { 
	this->cust_id = number_of_customers + 1;
	number_of_customers++;
	this->cust_fname = "default";
	this->cust_lname = "value";
}

// Constructor with user defined member variables
Customer::Customer(std::string fname, std::string lname) {
	this -> cust_id = number_of_customers + 1;
	number_of_customers++;
	this->cust_fname = fname;
	this->cust_lname = lname;

	cout << cust_id << " :" << cust_fname << " :" << cust_lname << "." << endl;
}

int Customer::get_cust_id() {
	return this->cust_id;
}

string Customer::get_cust_fname() {
	return this->cust_fname;
}

string Customer::get_cust_lname() {
	return this->cust_lname;
}

void Customer::set_id(int id) {
	cust_id = id;
}

void Customer::set_cust_fname(string fname) {
	cust_fname = fname;
}

void Customer::set_cust_lname(string lname) {
	cust_lname = lname;
}

//void Customer::update_db() {
//	int rc = sqlite3_open(db_location, &db);
//	int id = cust.get_cust_id();
//	check_db_errors(rc);
//	string d = std::to_string(cust.get_cust_id());
//	string instructions = "INSERT INTO CUSTOMERS (cust_id,cust_first_name,cust_last_name)\
//		VALUES(" + d + ", '" + cust.get_cust_fname() + "', '" + cust.get_cust_lname() + "'); ";
//	cout << instructions << endl;
//	rc = sqlite3_exec(db, instructions.c_str(), NULL, 0, &err_msg);
//	sqlite3_close(db);
//}
