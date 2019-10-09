// 142_detectCycle.cpp : 定义控制台应用程序的入口点。
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
	//时间复杂度和空间复杂度更低
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

