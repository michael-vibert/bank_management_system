#pragma once
#include <string>
#include "Customer.h"

class Trans {
private:
	Customer withdraw_cust;
	Customer deposit_cust;
	double trans_amount;
	int trans_id;
	std::string trans_date_time;
	bool trans_valid;

public:

	Trans();
	Trans(double trans_amount, Customer withdraw_cust, Customer deposit_cust);
	bool validate_trans();
	void print_receipt();
};