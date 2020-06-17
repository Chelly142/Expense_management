#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "event_expense.h"
#include<iostream>
#include <ctime>
using namespace std;

int event_Expense::calc_expense() {
	return expense;
}
void event_Expense::out_expense() {
	time_t t = time(NULL);
	struct  tm* tm;
	tm = localtime(&t);
	int curr_month = tm->tm_mon + 1;
	cout << "지출명: " << this->name << endl;
	cout << "지출일: " << curr_month << "월 " << this->day << "일" << endl;
	cout << "총 지출액: " << this->expense << endl;
	cout << endl;
}
event_Expense::event_Expense(int d, int mon ,char name[40]) {

	this->day = d;
	this->expense = mon;
	strcpy(this->name, name);
	this->expense_type = 2; //이벤트 지출 타입 2
}