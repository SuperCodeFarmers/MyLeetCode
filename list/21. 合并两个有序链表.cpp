/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

   ListNode* begin = new ListNode(-20000000, l1);

   ListNode* temp = begin;

   // 遍历l2链表,把l2的所有结点插入l1中
   while (l2)
   {
       while (temp->next != nullptr && temp->next->val <= l2->val)
       {
           temp = temp->next;
       }
       ListNode* now = l2;
       l2 = l2->next;
       now->next = temp->next;
       temp->next = now;
       temp = temp->next;
   }
   
    return begin->next;
}

ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    ListNode* dummy = new ListNode(-200000);
    ListNode* temp = dummy;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val < p2->val) {
            temp->next = p1;
            p1 = p1->next;
        } else {
            temp->next = p2;
            p2 = p2->next;
        }
        temp = temp->next;
    }
    if (p1 != nullptr) {
        temp->next = p1;
    }
    if (p2 != nullptr) {
        temp->next = p2;
    }
    return dummy->next;
}