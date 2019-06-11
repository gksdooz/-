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

bankAccount::bankAccount() //������
{

}

bankAccount::~bankAccount() //�Ҹ���
{

}

string bankAccount::getDate() //��¥�� ����Ʈ�ϴ� �Լ�
{
    char dateStr[9];
    _strdate_s(dateStr);
    return dateStr;
}

float bankAccount::view_balance() //cash_balance�� ����Ʈ�ϴ� �Լ�
{
    cout<<"Your account balance is "<<cash_balance<<"$\n";
    return cash_balance;
}

void bankAccount::deposit_bank(float money) //bank account�� ���� �Ա��ϴ� �Լ�
{
    cash_balance+=money;
    cout<<"Your cash balance after depositing "<<money<<"$ is "<<cash_balance<<"$"<<endl;

	//�ŷ� ������ log file�� �����
    ofstream myfile;
    myfile.open("bank_transaction_history.txt",ios::app);
    if(myfile.is_open())//myfile�� ���µȴٸ� �Ʒ��� ���
    {
        myfile.eof();
        myfile<<"\nDeposit\t\t$"<<money<<"\t"<<getDate()<<"\t$"<<cash_balance<<endl;
    }
    else//������ �ȵȴٸ� �Ʒ��� ���.
    {
        cout<<"Cannot record this transaction. File opening failed.\n";
    }
}

void bankAccount::withdraw_bank(float money) //bank account���� ���� ����ϴ� �Լ�
{
    if(money<cash_balance)
    {
        cash_balance-=money;
        cout<<"Your cash balance after withdrawal of "<<money<<"$ is "<<cash_balance<<"$"<<endl;

		//�ŷ� ������ log file�� �����
        ofstream myfile;
        myfile.open("bank_transaction_history.txt",ios::app);
        if(myfile.is_open())//myfile�� ���µȴٸ� �Ʒ��� ���
        {
            myfile<<"\nWithdrawal\t$"<<money<<"\t"<<getDate()<<"\t"<<cash_balance<<endl;
        }
        else//������ �ȵȴٸ� �Ʒ��� ���.
        {
            cout<<"Cannot record this transaction. File opening failed.\n";
        }
    }
    else
        cout<<"Transaction failed. Insufficient balance\n";
}

void bankAccount::print_bankHistory() //bank account�� �ŷ������� ����Ʈ�ϴ� �Լ�
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

float bankAccount::getBalance() //balance�� get�ϴ� �Լ�
{
	return cash_balance;
}

void bankAccount::setBalance(float blnc) //balance�� set�ϴ� �Լ�
{
	cash_balance=blnc;
}



