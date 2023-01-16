#include <iostream>
#include <string>
#include "sqlite3.h"
#include "Connection.h"
#include "Customer.h"

using namespace std;



//int main() {
//	//int d = 0;
//	//const char* x = "Customers";
//	//
//	//Connection m;
//	//cout << m.open_db(d, x) << endl;
//
//	Customer katie(005, "Katie", "Webb");
//	const char* sql = "INSERT INTO Customers(cust_id,cust_first_name,cust_last_name) \
//					   VALUES (5, 'Katie', 'Webb');";
//	Connection conn;
//	conn.transaction(sql);
//
//	return 0;
//}
