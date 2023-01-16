#include <iostream>
#include <string>
#include "Connection.h"
#include "Account.h"
#include "Branch.h"
#include "Customer.h"
#include <initializer_list>
#include "Trans.h"

using namespace std;

// test structure for storing the transaction variables
struct insert_into {
	string table;
	int id;
	string fname;
	string lname;
};


string branch_insert(Branch this_b) {
	return "INSERT INTO Branch(branch_id, branch_name)\n"
		"VALUES(" + to_string(this_b.get_branch_id()) + ", '" + this_b.get_branch_name() + "');";
}

 //test function for inserting the variables into the sql statement
string combiner(insert_into info) {
	return "INSERT INTO " + info.table + "(cust_id, cust_first_name, cust_last_name)\n"
			"VALUES(" + to_string(info.id) + ", '" + info.fname + "', '" + info.lname + "');";
}

int main() {
	Customer kaite("Kaite", "webb");
	Customer mike("Michael", "Vibert");
	Customer janet("Janet", "Borrego");
	Branch bunbury(1001, "Bunbury");
	Branch busselton(1002, "Busselton");
	Savings(5.5, 1004, bunbury, 40400.65, kaite);
	Savings(5.5, 1005, busselton, 300.68, janet);

	/*Trans(300.40, kaite, mike);*/

	/*cout << branch_insert(bunbury) << endl;
	Connection conn;
	conn.transaction(branch_insert(busselton));*/
	//Account savings("SAV001", bunbury, 0.0, mike);
	//Savings acc1(5.5, 1004, bunbury, 0.0, janet);
	//double f = 4000.7;
	//acc1.set_balance(f, true);
	//cout << acc1.get_acc_balance() << endl;
	//cout << acc1.get_acc_prefix() << acc1.get_acc_id() << endl;



	//acc1.print_details();

}