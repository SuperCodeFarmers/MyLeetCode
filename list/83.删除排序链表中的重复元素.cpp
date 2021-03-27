 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p = head;
    while(p != nullptr) {
        if (nullptr == p->next) {
            break;
        }

        if (p->val == p->next->val) {
            ListNode* temp = p->next;
            p->next = temp->next;
            delete temp;
            continue;
        }

        p = p->next;
    }
    return head;
}
