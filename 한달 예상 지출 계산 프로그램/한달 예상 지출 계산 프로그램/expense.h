#include <cstddef>
#include <vector>
#pragma once
class Expense {
public:
	char name[40];
	virtual int calc_expense()=0;
	virtual void out_expense()=0;
	int expense;
	int expense_type;
};
