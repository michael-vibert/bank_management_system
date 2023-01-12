#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() {}

Account::Account(const char* acc_id, Branch branch_id, double balance, Customer cust) {
	this->acc_id = acc_id;
	this->acc_branch = branch_id;
	this->acc_balance = balance;
	this->acc_cust = cust;
	cout << "New Account Created!"<< endl;
	print_details();
}

int Account::get_branch_id() {
	return acc_branch.get_branch_id();
}

const char* Account::get_acc_id()
{
	return acc_id;
}

double Account::get_acc_balance() {
	return acc_balance;
}

void Account::set_balance(double amount, bool deposit) {
	if (deposit) {
		acc_balance += amount;
	}
	else 
		acc_balance -= amount;
}

void Account::print_details() {
	cout << "Account Owner: " << acc_cust.get_cust_fname() << " " << acc_cust.get_cust_lname() << endl;
	cout << "Account Id: " << acc_id << endl;
	cout << "Account Branch: " << acc_branch.get_branch_name() << endl;
	cout << "Account Balance: " << acc_balance << endl;
}

// derived account type 1 - Savings

Savings::Savings(double interest_rate, const char* acc_id, Branch this_branch, double balance, Customer this_cust) : Account(acc_id, this_branch, balance, this_cust)
{
	acc_id = acc_id;
	cout << "New Account Created!" << endl;
	print_details();
	this->interest_rate = interest_rate;
	this->sav_acc_name = "Savings";
}
