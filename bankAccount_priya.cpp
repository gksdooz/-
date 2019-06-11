//Shanmukha Priya Loke
//December 13th, 2015
#include<string>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<time.h>
#include<cstdlib>
#include "bankAccount_priya.h"
#include "account_priya.h"
using namespace std;

bankAccount::bankAccount() //생성자
{

}

bankAccount::~bankAccount() //소멸자
{

}

string bankAccount::getDate() //날짜를 프린트하는 함수
{
    char dateStr[9];
    _strdate_s(dateStr);
    return dateStr;
}

float bankAccount::view_balance() //cash_balance를 프린트하는 함수
{
    cout<<"Your account balance is "<<cash_balance<<"$\n";
    return cash_balance;
}

void bankAccount::deposit_bank(float money) //bank account에 돈을 입금하는 함수
{
    cash_balance+=money;
    cout<<"Your cash balance after depositing "<<money<<"$ is "<<cash_balance<<"$"<<endl;

	//거래 내역을 log file에 기록함
    ofstream myfile;
    myfile.open("bank_transaction_history.txt",ios::app);
    if(myfile.is_open())//myfile이 오픈된다면 아래를 기록
    {
        myfile.eof();
        myfile<<"\nDeposit\t\t$"<<money<<"\t"<<getDate()<<"\t$"<<cash_balance<<endl;
    }
    else//오픈이 안된다면 아래를 기록.
    {
        cout<<"Cannot record this transaction. File opening failed.\n";
    }
}

void bankAccount::withdraw_bank(float money) //bank account에서 돈을 출금하는 함수
{
    if(money<cash_balance)
    {
        cash_balance-=money;
        cout<<"Your cash balance after withdrawal of "<<money<<"$ is "<<cash_balance<<"$"<<endl;

		//거래 내역을 log file에 기록함
        ofstream myfile;
        myfile.open("bank_transaction_history.txt",ios::app);
        if(myfile.is_open())//myfile이 오픈된다면 아래를 기록
        {
            myfile<<"\nWithdrawal\t$"<<money<<"\t"<<getDate()<<"\t"<<cash_balance<<endl;
        }
        else//오픈이 안된다면 아래를 기록.
        {
            cout<<"Cannot record this transaction. File opening failed.\n";
        }
    }
    else
        cout<<"Transaction failed. Insufficient balance\n";
}

void bankAccount::print_bankHistory() //bank account의 거래내역을 프린트하는 함수
{
    ifstream myfile;
    string line;
    myfile.open("bank_transaction_history.txt",ios::app);
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,line);
            cout<<line<<endl;
        }
        myfile.close();
    }
    else
        cout<<"Error in opening the file.\n";
}

float bankAccount::getBalance() //balance를 get하는 함수
{
	return cash_balance;
}

void bankAccount::setBalance(float blnc) //balance를 set하는 함수
{
	cash_balance=blnc;
}



