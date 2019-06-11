//Shanmukha Priya Loke
//December 13th, 2015
#ifndef ACCOUNT_PRIYA_H
#define ACCOUNT_PRIYA_H

class account //추상 기본 클래스
{
 public:
     account(); //생성자
     static float cash_balance;

     //추상 기본 클래스 순수 가상 함수
     virtual float getBalance()=0;
     virtual void setBalance(float)=0;
};
#endif // ACCOUNT_PRIYA_H
