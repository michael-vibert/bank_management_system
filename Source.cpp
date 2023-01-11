#include <iostream>
#include <string>
#include "Connection.h"
#include "Account.h"
#include "Branch.h"
#include "Customer.h"

using namespace std;

struct insert_into {
	string table;
	int id;
	string fname;
	string lname;
};

string combiner(insert_into info) {
	return "INSERT INTO " + info.table + "(cust_id, cust_first_name, cust_last_name)\n"
			"VALUES(" + to_string(info.id) + ", '" + info.fname + "', '" + info.lname + "');";
}

int main() {
	Customer kaite("Kaite", "webb");
	Customer mike("Michael", "Vibert");
	Customer janet("Janet", "Borrego");
	Branch bunbury(1001, "Bunbury");
	//Account savings("SAV001", bunbury, 0.0, mike);
	Savings acc1(5.5, "SAV1002", bunbury, 0.0, janet);
	double f = 4000.7;
	acc1.set_balance(f, true);
	//cout << acc1.get_acc_balance() << endl;
	//cout << acc1.get_acc_id() << endl;

	//acc1.print_details();

}