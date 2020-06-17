#include "expense.h"
#pragma once
class period_Expense : public Expense {
public:
	virtual int calc_expense();
	virtual void out_expense()override;
	period_Expense(int p, int pe, char name[40]);
	int period;
	int period_expense;
};

