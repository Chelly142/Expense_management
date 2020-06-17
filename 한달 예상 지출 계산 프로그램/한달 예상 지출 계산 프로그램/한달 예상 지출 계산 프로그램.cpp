#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma once
#include <iostream>
#include "expense.h"
#include "periodic_expense.h"
#include "event_expense.h"
#include "extra_expense.h"
#include <vector>
#include <ctime>
#include"menu.h"
using namespace std;

/*void add_expense(vector<Expense*> &e);
void out_all_expense(vector<Expense*> &e);
void out_one_expense(vector<Expense*> &e);
void delete_expense(vector<Expense*> &e);
void clear_expense(vector<Expense*> &e);
void all_expense(vector<Expense*> &e);
void out_type(vector<Expense*> &e);
*/
int main()
{
	vector<Expense*> e;
	int n = 1;
	menu:
	while (n != 0) {
		cout << "==========[ M E N U ] ==========" << endl;
		cout << "1.모든 지출 출력" << endl;
		cout << "2.원하는 특정 지출 정보 출력" << endl;
		cout << "3.지출 입력" << endl;
		cout << "4.원하는 지출 삭제" << endl;
		cout << "5.모든 지출 삭제" << endl;
		cout << "6.총 지출 합 출력" << endl;
		cout << "7.지출 종류 별 정보 출력" << endl;
		cout << "0.프로그램 종료" << endl;
		cout << "================================" << endl;
		cout << "원하는 메뉴를 선택 하십쇼: ";
		cin >> n;
		cout << "================================" << endl;
		cout << endl;
		if (n == 0)
			break;
		switch (n)
		{
		case 1:
			out_all_expense(e);
			break;
		case 2:
			out_one_expense(e);
			break;
		case 3:
			add_expense(e);
			break;
		case 4:
			delete_expense(e);
			break;
		case 5:
			clear_expense(e);
			break;
		case 6:
			all_expense(e);
			break;
		case 7:
			out_type(e);
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}
