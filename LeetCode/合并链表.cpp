#include<iostream>

struct ListNode
{
	ListNode* next;
	int value;
};

ListNode* mergeTwoOrderedLists(ListNode* pHead1, ListNode* pHead2) {

	ListNode* newHead = NULL;//合并后的头结点
	ListNode* pTail = NULL;//合并后的未节点

	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}
	else
	{
		if (pHead1->value < pHead2->value)
		{
			newHead = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			newHead = pHead2;
			pHead2 = pHead2->next;
		}

		pTail = newHead;//指向第一个节点
		while (pHead1 && pHead2)
		{
			if (pHead1->value < pHead2->value)
			{
				pTail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				pTail->next = pHead2;
				pHead2 = pHead2->next;
			}
			pTail = pTail->next;
		}

		if (NULL == pHead1)
		{
			pTail->next = pHead2;
			pHead2 = pHead2->next;
		}else if (NULL == pHead2)
		{
			pTail->next = pHead1;
			pHead1 = pHead1->next;
		}

	}

	return newHead;


}