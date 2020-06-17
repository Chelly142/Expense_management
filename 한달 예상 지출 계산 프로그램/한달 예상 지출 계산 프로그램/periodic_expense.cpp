#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "periodic_expense.h"
#include "expense.h"
#include <iostream>
#include <ctime>

using namespace std;

int period_Expense::calc_expense() {
	time_t t = time(NULL); //이번 달이 총 몇일인지 받아오기
	struct  tm* tm;
	tm = localtime(&t);
	int curr_month = tm->tm_mon + 1;
	int curr_year = tm->tm_year; //윤년 판별을 위해
	int month_day = 0;
	switch (curr_month)// 월별로 총 일수가 다르다
	{
	case(1):
		month_day = 31;
		break;
	case(2)://2월은 윤년을 판별해준다.
		if ((curr_year % 4 == 0 && curr_year % 100 != 0) || curr_year % 400 == 0)
			month_day = 29;
		else
			month_day = 28;
		break;
	case(3):
		month_day = 31;
		break;
	case(4):
		month_day = 30;
		break;
	case(5):
		month_day = 31;
		break;
	case(6):
		month_day = 30;
		break;
	case(7):
		month_day = 31;
		break;
	case(8):
		month_day = 31;
		break;
	case(9):
		month_day = 30;
		break;
	case(10):
		month_day = 31;
		break;
	case(11):
		month_day = 30;
		break;
	case(12):
		month_day = 31;
		break;
	default:
		break;
	}
	return period_expense * (month_day / period + 1);
}
void period_Expense::out_expense() { //출력 함수
	cout << "지출명: " << this->name << endl;
	cout << "지출주기: " << this->period << endl;
	cout << "주기당 지출: " << this->period_expense << endl;
	cout << "총 지출액: " << this->expense << endl;
	cout << endl;
}

period_Expense::period_Expense(int p, int pe, char name[40]) {
	period = p;
	period_expense = pe;
	strcpy(this->name, name);
	this->expense_type = 1; //주기적 지출 타입 1
	this->expense = calc_expense();
}
