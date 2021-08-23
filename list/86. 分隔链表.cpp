/*
86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。

示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]

示例 2：
输入：head = [2,1], x = 2
输出：[1,2]
 

提示：
链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/*
使用双指针法，
一个指针指向全小于target的链表，一个指针指向大于等于target的链表，最后把两个链表进行合并。
并把大于等于target的链表最后一个指针指向置空。

两个虚拟头，遍历原来的链表一遍进行归类，小于x的归于虚拟头1之后，其余的归于虚拟头2之后，再把虚拟头2后面的链表接到虚拟头1链表后面即可。
*/

ListNode* partition(ListNode* head, int x) {
    ListNode* list1 = new ListNode();
    ListNode* l1 = list1;
    ListNode* list2 = new ListNode();
    ListNode* l2 = list2;
    ListNode* p = head;
    while (p)
    {
        if (p->val < x) {
            l1->next = p;
            l1 = l1->next; // 等同 l1 = p;

        } else {
            l2->next = p;
            l2 = l2->next; // 等同 l2 = p;
        }
        p = p->next;
    }
    l2->next = nullptr;
    l1->next = list2->next;
    return list1->next;
}