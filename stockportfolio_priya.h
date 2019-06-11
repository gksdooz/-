//Shanmukha Priya Loke
//December 13th, 2015

#ifndef STOCKPORTFOLIO_PRIYA_H
#define STOCKPORTFOLIO_PRIYA_H

#include "account_priya.h"
#include<string>
using namespace std;

class ListNode //리스트 노드들의 구현
{
    friend class stockaccount; //stockaccount를 프렌드클래스로 선언
    public: //퍼블릭 멤버 함수
        ListNode(string& name,int numb)
        :symbol(name),number(numb)
        {
            this->next=NULL;
            this->prev=NULL;
        }

private:
    string symbol; //리스트의 심볼
    int number; 
    ListNode *next;//리스트의 next 노드
    ListNode *prev;//리스트의 prev 노드
};

class stockaccount:public account //클래스 account로 부터 퍼블릭 상속
{
public:
    stockaccount(); //생성자
	//멤버함수 선언
    static float total_portfolio_value;
    void display();
    void current_portfolio();
    void buy_shares();
    void addNode(ListNode *);
    void sell_shares();
    void delNode(string node);
    void transac_history();
    void update_stocks();
    string getTime();

	//Merge Sort 작업을 구성하는 함수들
	ListNode *split(ListNode *);
    ListNode *merge_sort(ListNode *);
    ListNode *sortList(ListNode *first,ListNode *second);
    void sort_wrapper();
    virtual float getBalance();
	virtual void setBalance(float);
private:
    ListNode *firstPtr; //첫 번째노드의 포인터
    ListNode *lastPtr; //두 번째 노드의 포인터
    int size_list; //더블링크드리스트의 사이즈
};
#endif // STOCKPORTFOLIO_PRIYA_H
