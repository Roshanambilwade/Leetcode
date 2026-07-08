class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode* del = temp->next;
                temp->next = del->next;
                
            } else {
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};