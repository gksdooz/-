//Shanmukha Priya Loke
//December 13th, 2015
#ifndef BANKACCOUNT_PRIYA_H
#define BANKACCOUNT_PRIYA_H

#include "account_priya.h"
#include<string>
using namespace std;

class bankAccount:public account //클래스 "account"로 부터 상속
{
public:
	//멤버함수들 선언
    bankAccount();
	~bankAccount();
    float view_balance();
    void deposit_bank(float);
    void withdraw_bank(float);
    void print_bankHistory();
    string getDate();
	virtual float getBalance();
	virtual void setBalance(float);
};
#endif // BANKACCOUNT_PRIYA_H
