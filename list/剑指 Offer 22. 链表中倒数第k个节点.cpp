/*
剑指 Offer 22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

 

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
*/


/*
解法：
单链表的倒数第 k 个节点
从前往后寻找单链表的第 k 个节点很简单，一个 for 循环遍历过去就找到了，但是如何寻找从后往前数的第 k 个节点呢？

那你可能说，假设链表有 n 个节点，倒数第 k 个节点就是正数第 n - k 个节点，不也是一个 for 循环的事儿吗？

是的，但是算法题一般只给你一个 ListNode 头结点代表一条单链表，你不能直接得出这条链表的长度 n，而需要先遍历一遍链表算出 n 的值，然后再遍历链表计算第 n - k 个节点。

也就是说，这个解法需要遍历两次链表才能得到出倒数第 k 个节点。

那么，我们能不能只遍历一次链表，就算出倒数第 k 个节点？可以做到的，如果是面试问到这道题，面试官肯定也是希望你给出只需遍历一次链表的解法。

这个解法就比较巧妙了，假设 k = 2，思路如下：

首先，我们先让一个指针 p1 指向链表的头节点 head，然后走 k 步：

现在的 p1，只要再走 n - k 步，就能走到链表末尾的空指针了对吧？

趁这个时候，再用一个指针 p2 指向链表头节点 head：

接下来就很显然了，让 p1 和 p2 同时向前走，p1 走到链表末尾的空指针时走了 n - k 步，p2 也走了 n - k 步，也就是链表的倒数第 k 个节点：

这样，只遍历了一次链表，就获得了倒数第 k 个节点 p2。

上述逻辑的代码如下：

// 返回链表的倒数第 k 个节点
ListNode findFromEnd(ListNode head, int k) {
    ListNode p1 = head;
    // p1 先走 k 步
    for (int i = 0; i < k; i++) {
        p1 = p1.next;
    }
    ListNode p2 = head;
    // p1 和 p2 同时走 n - k 步
    while (p1 != null) {
        p2 = p2.next;
        p1 = p1.next;
    }
    // p2 现在指向第 n - k 个节点
    return p2;
}


*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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