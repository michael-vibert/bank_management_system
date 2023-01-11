#pragma once
#include <string>
#include "Customer.h"
#include "Branch.h"

using namespace std;

class Account
{
public:
	const char* acc_id;
	Branch acc_branch;
	double acc_balance;
	Customer acc_cust;
public:
	Account();
	Account(const char* acc_id, Branch this_branch, double balance, Customer this_cust);
	int get_branch_id();
	const char* get_acc_id();
	double get_acc_balance();
	void set_balance(double amount, bool deposit);
	void print_details();
};

class Savings : public Account {
private:
	double interest_rate;
	string sav_acc_name = "Savings";
public: 
	Savings(double interest_rate, Account(const char* acc_id, Branch this_branch, double balance, Customer this_cust));
};