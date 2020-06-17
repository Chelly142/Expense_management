#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "extra_expense.h"
#include<iostream>
using namespace std;

int extra_Expense::calc_expense() {
	this->expense = max;
	return expense;
}
void extra_Expense::out_expense() {
	cout << "지출명: " << this->name << endl;
	cout << "최대 지출액: " << this->max << endl;
	cout << "최소 지출액: " << this->min << endl;
	cout << endl;
}
extra_Expense::extra_Expense(int max,int min, char name[40]) {
	this->max = max;
	this->min = min;
	strcpy(this->name, name);
	this->expense = this->calc_expense();
	this->expense_type = 3; //여유 지출 타입 3
}