/*
82. 删除排序链表中的重复元素 II
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]

示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3] 

提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 只删除重复的结点
ListNode *deleteDuplicates1(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = p->next;
    while (q)
    {
        if (p->val == q->val)
        {
            ListNode *temp = q;
            q = q->next;
            temp->next = nullptr;
            p->next = q;
            delete temp;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

ListNode *deleteDuplicates2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *p = head;
    ListNode *q = p->next;
    vector<int> repet;
    while (q)
    {
        if (p->val == q->val)
        {
            ListNode *temp = q;
            q = q->next;
            temp->next = nullptr;
            p->next = q;
            if (repet.size() == 0)
            {
                repet.push_back(temp->val);
            }
            else if (repet.back() != temp->val)
            {
                repet.push_back(temp->val);
            }
            delete temp;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    if (repet.size() == 0)
    {
        return head;
    }

    ListNode *newHead = new ListNode(-1000, head);
    ListNode *ret = newHead;
    p = newHead->next;
    while (p)
    {
        if (p->val == repet.front())
        {
            ListNode *temp = p;
            p = p->next;
            newHead->next = p;
            delete temp;
            repet.erase(repet.begin());
        }
        else
        {
            p = p->next;
            newHead = newHead->next;
        }
    }
    return ret->next;
}

// 使用递归解
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    if (head->val != head->next->val) {
        head->next = deleteDuplicates(head->next);
    } else if (head->val == head->next->val) {
        ListNode* move = head->next;
        while (move && head->val == move->val) {
            move = move->next;
        }
        return deleteDuplicates(move);
    }
    return head;
}