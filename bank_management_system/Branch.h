#pragma once
#include <string>
class Branch
{
private:
	int branch_id;
	std::string branch_name;
public:
	Branch();
	Branch(int branch_id, std::string name);
	int get_branch_id();
	std::string get_branch_name();
};

