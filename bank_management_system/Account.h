#pragma once
#include <string>
#include "Customer.h"
#include "Branch.h"

using namespace std;

class Account
{
public:
	int acc_id;
	Branch acc_branch;
	double acc_balance;
	Customer acc_cust;
public:
	Account();
	Account(int acc_id, Branch this_branch, double balance, Customer this_cust);
	int get_branch_id();
	int get_acc_id();
	double get_acc_balance();
	void set_balance(double amount, bool deposit);
	void print_details();
};

class Savings : public Account {
private:
	const char* acc_prefix = "SAV";
	double interest_rate;
	string sav_acc_name = "Savings";
public: 
	Savings(double interest_rate, int acc_id, Branch this_branch, double balance, Customer this_cust);
	const char* get_acc_prefix();
};
