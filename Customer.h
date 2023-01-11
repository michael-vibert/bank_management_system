#pragma once
#include <string>

class Customer
{
private:
	int cust_id = 0;
	std::string cust_fname;
	std::string cust_lname;
public:
	Customer();
	Customer(std::string fname, std::string lname);
	int get_cust_id();
	std::string get_cust_fname();
	std::string get_cust_lname();
	void set_id(int id);
	void set_cust_fname(std::string fname);
	void set_cust_lname(std::string lname);
	void update_db();
};