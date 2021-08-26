/*
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：
输入：head = [5], left = 1, right = 1
输出：[5] 

提示：
链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n 

进阶： 你可以使用一趟扫描完成反转吗？
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverse(ListNode* head) {
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

/*
第 1 步：先将待反转的区域反转；
第 2 步：把 pre 的 next 指针指向反转以后的链表头节点，把反转以后的链表的尾节点的 next 指针指向 succ。
*/

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* dummyNode = new ListNode(0, head);
    ListNode* pre = dummyNode;
    for (int i = 0; i < left - 1; ++i) {
        pre = pre->next;
    }
    ListNode* leftNode = pre->next;
    ListNode* rightNode = leftNode;
    for (int i = 0; i < right - left; ++i) {
        rightNode = rightNode->next;
    }
    ListNode* succ = rightNode->next;
    pre->next = nullptr;
    rightNode->next = nullptr;
    ListNode* ret = reverse(leftNode);

    pre->next = rightNode;
    leftNode->next = succ;
    return dummyNode->next;
}