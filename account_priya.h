//Shanmukha Priya Loke
//December 13th, 2015
#ifndef ACCOUNT_PRIYA_H
#define ACCOUNT_PRIYA_H

class account //�߻� �⺻ Ŭ����
{
 public:
     account(); //������
     static float cash_balance;

     //�߻� �⺻ Ŭ���� ���� ���� �Լ�
     virtual float getBalance()=0;
     virtual void setBalance(float)=0;
};
#endif // ACCOUNT_PRIYA_H
