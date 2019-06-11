//Shanmukha Priya Loke
//December 13th, 2015

#ifndef STOCKPORTFOLIO_PRIYA_H
#define STOCKPORTFOLIO_PRIYA_H

#include "account_priya.h"
#include<string>
using namespace std;

class ListNode //����Ʈ ������ ����
{
    friend class stockaccount; //stockaccount�� ������Ŭ������ ����
    public: //�ۺ� ��� �Լ�
        ListNode(string& name,int numb)
        :symbol(name),number(numb)
        {
            this->next=NULL;
            this->prev=NULL;
        }

private:
    string symbol; //����Ʈ�� �ɺ�
    int number; 
    ListNode *next;//����Ʈ�� next ���
    ListNode *prev;//����Ʈ�� prev ���
};

class stockaccount:public account //Ŭ���� account�� ���� �ۺ� ���
{
public:
    stockaccount(); //������
	//����Լ� ����
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

	//Merge Sort �۾��� �����ϴ� �Լ���
	ListNode *split(ListNode *);
    ListNode *merge_sort(ListNode *);
    ListNode *sortList(ListNode *first,ListNode *second);
    void sort_wrapper();
    virtual float getBalance();
	virtual void setBalance(float);
private:
    ListNode *firstPtr; //ù ��°����� ������
    ListNode *lastPtr; //�� ��° ����� ������
    int size_list; //����ũ�帮��Ʈ�� ������
};
#endif // STOCKPORTFOLIO_PRIYA_H
