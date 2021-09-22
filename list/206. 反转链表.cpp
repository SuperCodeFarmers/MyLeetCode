/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 
示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
 

提示：
链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* p = nullptr;
    ListNode* q = head;
    while (q)
    {
        ListNode* temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    return p;
}

ListNode* reverseList2(ListNode* head) {
    if (head->next == nullptr) {
        return head;
    }
    ListNode* ret = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ret;
}

//反转以head为起点的n个结点，返回新的头结点
ListNode* success;
ListNode* reverseListN(ListNode* head, int n) {
    if (n == 1) {
        // 记录第n+1个结点
        success = head->next;
        return head;
    }
    // 以head->next为起点，需要反转前n-1个结点
    ListNode* ret = reverseListN(head->next, n - 1);

    head->next->next = head;
    // 反转之后的head结点和后面的结点连接起来
    head->next = success;
    return ret;
}

//一部分
ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (m == 1) {
        return reverseListN(head, n);
    }
    // 我们可以把反转一部分变为反转前N个
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
}
