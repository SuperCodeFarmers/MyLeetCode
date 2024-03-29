/*
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
 

提示：
链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* q = head;
    while (q)
    {
        ++len;
        q = q->next;
    }

    int count = len - n + 1;

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* p = dummyHead;
    while (--count)
    {
        p = p->next;
        /* code */
    }
    ListNode* deleteNode = p->next;
    p->next = deleteNode->next;
    delete deleteNode;

    ListNode* retNode = dummyHead->next;
    delete dummyHead;
    return retNode;
}

// 遍历一遍的解法
ListNode *getKthFromEnd(ListNode *head, int k)
{
    int len = 0;
    ListNode *p = head;
    while (len < k)
    {
        ++len;
        p = p->next;
    }
    int count = len - k;
    ListNode *p2 = head;
    while (p)
    {
        p = p->next;
        p2 = p2->next;
    }
    return p2;
}