#include "Trans.h"
#include "Customer.h"
#include "Branch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

std::string get_time()
{
	time_t ti = time(nullptr);
	auto tm = localtime_s(ti);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	auto str = oss.str();

	return str;
}
Trans::Trans()
{
}

Trans::Trans(double trans_amount, Customer withdraw_cust, Customer deposit_cust)
{
	this->trans_id = 1;// query the database and find out what number we up to
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
	cout << trans_id << endl;
	cout << trans_date_time << endl;
	cout << trans_amount << endl;
	cout << withdraw_cust.get_cust_fname() << endl;
	cout << deposit_cust.get_cust_fname() << endl;
	cout << trans_valid << endl;
}
