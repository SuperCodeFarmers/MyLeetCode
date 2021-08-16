/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
 

提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
 

进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）

通过次数295,442提交次数420,966


------多进行两层的判断就行了----------
*/


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* p = new ListNode(-10000, head);
    ListNode* ret = p;
    while (p->next != nullptr && p->next->next != nullptr)
    {
        ListNode* q = p->next;
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        p = p->next->next;
    }
    return ret->next;
}