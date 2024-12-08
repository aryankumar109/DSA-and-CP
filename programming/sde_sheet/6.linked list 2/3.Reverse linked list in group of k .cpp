class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        
        for (int i = 0; i < length / k; i++) {
            curr = prev->next;
            next = curr->next;
            
            for (int j = 1; j < k; j++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            
            prev = curr;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};