#include "Branch.h"
#include <string>
#include <iostream>

using namespace std;

Branch::Branch(){}

Branch::Branch(int branch_id, std::string name) {
	this->branch_id = branch_id;
	this->branch_name = name;
	cout << "New Branch created! \nBranch name: " << branch_name << endl;
	cout << "Branch Id: " << branch_id << endl;
}

int Branch::get_branch_id() {
	return branch_id;
	
}

std::string Branch::get_branch_name()
{
	return branch_name;
}
