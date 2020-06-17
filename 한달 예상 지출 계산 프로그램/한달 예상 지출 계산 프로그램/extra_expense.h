#pragma once
#include "expense.h"
class extra_Expense :public Expense {
public:
	virtual int calc_expense();
	virtual void out_expense()override;
	extra_Expense(int max, int min, char name[40]);
	int max;
	int min;
};