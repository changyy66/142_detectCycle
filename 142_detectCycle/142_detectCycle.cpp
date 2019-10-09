// 142_detectCycle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <set>
#include <iostream>

using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head)return head;
		//ListNode *first = head->next;
		ListNode *next = head;
		set<ListNode *> m;
		m.insert(next);
		while (NULL != next)
		{
			next = next->next;
			if (m.count(next) > 0)return next;
			m.insert(next);
		}
		return NULL;
	}
	//ʱ�临�ӶȺͿռ临�Ӷȸ���
	ListNode *detectCycle1(ListNode *head) {
		if (!head)return head;
		ListNode *first = head->next;
		ListNode *next = head;
		
		while (1)
		{
			if (!first)return NULL;
			first = first->next;
			if (!next)return NULL;
			next = next->next;
			if (first == next)break;
			
			if (!first)return NULL;
			first = first->next;
		}
		first = head;
		while (first!=next)
		{
			first = first->next;
			next = next->next;
		}
		return first;
	}
};
int main()
{
    return 0;
}

