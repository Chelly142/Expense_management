#pragma once
using namespace std;
#include "expense.h"
#include <iostream>
#include "periodic_expense.h"
#include "extra_expense.h"
#include <ctime>
#include "event_expense.h"

void add_expense(vector<Expense*>& e) {
	int n;
	cout << "입력을 원하는 지출 종류가 무엇입니까?" << endl << endl;
	cout << "1.주기적 지출   2.이벤트 지출   3.여유 지출" << endl << endl;
	cout << "원하시는 지출 종류를 선택해주세요: ";
	cin >> n;
	cout << "================================" << endl;
	if (n == 1) {
		char name[40];
		int period, period_expense;
		cout << endl << "지출명을 입력해주십쇼: ";
		cin.ignore();
		cin.getline(name, 40);
		cout << endl << "지출주기를 입력해주십쇼: ";
		cin >> period;
		cout << endl << "주기당 지출을 입력해주십쇼: ";
		cin >> period_expense;
		period_Expense* pp = new period_Expense(period, period_expense, name);
		e.push_back(pp);
	}
	if (n == 2) {
		char name[40];
		int day;
		int mon;
		cin.ignore();
		cout << endl << "지출명을 입력해주십쇼: ";
		cin.getline(name, 40);
		cout << endl << "지출일을 입력해주십쇼: ";
		cin >> day;
		cout << endl << "지출액을 입력해주십쇼: ";
		cin >> mon;
		event_Expense* ep = new event_Expense(day, mon, name);
		e.push_back(ep);
	}
	if (n == 3) {
		char name[40];
		int max;
		int min;
		cout << endl << "지출명을 입력해주십쇼: ";
		cin.ignore();
		cin.getline(name, 40);
		cout << endl << "최대 지출액을 입력해주십쇼: ";
		cin >> max;
		cout << endl << "최소 지출액을 입력해주십쇼: ";
		cin >> min;
		extra_Expense* ep = new extra_Expense(max, min, name);
		e.push_back(ep);
	}
	cout << endl;
}
void out_all_expense(vector<Expense*>& e) {
	if (e.empty())
		cout << "저장되어있는 지출 정보가 없습니다." << endl;

	else {
		for (int i = 0; i < (int)e.size(); i++)
			e[i]->out_expense();
	}

}

void out_one_expense(vector<Expense*> & e) {
	vector<Expense*>::iterator it;
	char name[40];
	cout << "원하시는 지출정보의 이름을 입력하세요: ";
	cin.ignore();
	cin.getline(name, 40);
	cout << "================================" << endl;
	it = e.begin();
	while (true) {
		Expense* ee = *it;
		if (strcmp(ee->name, name) == 0) {
			ee->out_expense();
			break;
		}
		it++;
		if (it == e.end()) {
			cout << "입력하신 이름과 일치하는 지출정보가 존재하지 않습니다." << endl;
			break;
		}
	}
}

void delete_expense(vector<Expense*> & e) {
	vector<Expense*>::iterator it;
	char name[40];
	cout << "원하시는 지출정보의 이름을 입력하세요: ";
	cin.ignore();
	cin.getline(name, 40);
	cout << "================================" << endl;
	it = e.begin();
	while (true) {
		Expense* ee = *it;
		if (strcmp(ee->name, name) == 0) {
			e.erase(it);
			cout << name << " 지출 정보가 삭제되었습니다." << endl;
			break;
		}
		it++;
		if (it == e.end()) {
			cout << "입력하신 이름과 일치하는 지출정보가 존재하지 않습니다." << endl;
			break;
		}
	}
}

void clear_expense(vector<Expense*> & e) {
	e.clear();
	cout << "모든 지출 정보가 삭제되었습니다." << endl;
}

void all_expense(vector<Expense*> & e) {
	int period_expense_sum = 0;
	int extra_expense_sum = 0;
	int event_expense_sum = 0;
	int sum;
	time_t t = time(NULL);
	struct  tm* tm;
	tm = localtime(&t);
	int curr_month = tm->tm_mon + 1;
	for (int i = 0; i < (int)e.size(); i++) {
		switch (e[i]->expense_type)
		{
		case 1:
			period_expense_sum += e[i]->expense;
			break;
		case 2:
			event_expense_sum += e[i]->expense;
			break;
		case 3:
			extra_expense_sum += e[i]->expense;
			break;
		default:
			break;
		}
	}
	sum = period_expense_sum + event_expense_sum + extra_expense_sum;
	cout << curr_month << "월 예상 지출:" << sum << "원" << endl;
	cout << "총 주기적 지출:" << period_expense_sum << "원" << endl;
	cout << "총 이벤트 지출:" << event_expense_sum << "원" << endl;
	cout << "총 여유 지출:" << extra_expense_sum << "원" << endl << endl;
}

void out_type(vector<Expense*> & e) {
	int n;
	if (e.empty()) 
		cout << "저장되어있는 지출 정보가 없습니다." << endl;
	else {
		cout << "출력을 원하는 지출 종류가 무엇입니까?" << endl;
		cout << endl;
		cout << "1.주기적 지출   2.이벤트 지출   3.여유 지출" << endl << endl;
		cout << "원하시는 지출 종류를 선택해주세요: ";
		cin >> n;
		cout << "================================" << endl;

		for (int i = 0; i < (int)e.size(); i++) {
			switch (n)
			{
			case 1:
				if (e[i]->expense_type == n)
					e[i]->out_expense();
				break;
			case 2:
				if (e[i]->expense_type == n)
					e[i]->out_expense();
				break;
			case 3:
				if (e[i]->expense_type == n)
					e[i]->out_expense();
				break;

			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}
		}
	}
}