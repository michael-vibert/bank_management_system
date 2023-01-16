#include "Trans.h"
#include "Customer.h"
#include "Branch.h"
#include "Connection.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

std::string get_time()
{
	time_t givemetime = time(NULL);

	auto str = ctime(&givemetime);

	return str;
}

Trans::Trans(double trans_amount, Customer withdraw_cust, Customer deposit_cust)
{
	this->trans_id = get_highest();// query the database and find out what number we up to
	this->trans_date_time = get_time();
	this->withdraw_cust = withdraw_cust;
	this->deposit_cust = deposit_cust;
	this->trans_amount = trans_amount;
	trans_valid = true;
	print_receipt();
}

bool Trans::validate_trans()
{
	return false;
}

void Trans::print_receipt()
{
	cout << "====Transaction Receipt====" << endl;
	cout << "I.D       :  " << trans_id << endl;
	cout << "Date/Time : " << trans_date_time;
	cout << "Amount    : " << trans_amount << endl;
	cout << "From      : " << withdraw_cust.get_cust_fname() << endl;
	cout << "To        : " << deposit_cust.get_cust_fname() << endl;
}

int Trans::get_highest() {
	Connection conn;
	conn.transaction_v2("SELECT MAX(trans_id) FROM trans");
	return 1;
}
	


