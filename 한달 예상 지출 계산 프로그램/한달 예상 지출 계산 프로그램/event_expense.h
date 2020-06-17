#pragma once
#include "expense.h"

class event_Expense :public Expense {
public:
	virtual int calc_expense();
	virtual void out_expense()override;
	event_Expense(int d, int mon, char name[40]);
	int day;
};