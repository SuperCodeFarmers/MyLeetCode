/*
61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *ret = head;
    int len = 0;
    ListNode *p = head;
    while (p)
    {
        ++len;
        p = p->next;
    }
    int n = k % len;
    if (n == 0)
    {
        return head;
    }
    int count = len - n - 1;
    ListNode *newHead = head;
    ListNode *retHead = nullptr;
    while (count)
    {
        newHead = newHead->next;
        count--;
    }
    retHead = newHead->next;
    ListNode *retNextHead = retHead;
    newHead->next = nullptr;
    while (retNextHead->next)
    {
        retNextHead = retNextHead->next;
    }
    retNextHead->next = ret;
    return retHead;
}