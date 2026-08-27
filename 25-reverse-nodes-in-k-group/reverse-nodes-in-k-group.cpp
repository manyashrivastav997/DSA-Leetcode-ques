class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // Dummy node helps manage changes to the head easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;
        
        while (curr) {
            // Step 1: Check if there are at least k nodes remaining
            ListNode* groupTail = prevGroupTail;
            for (int i = 0; i < k; ++i) {
                groupTail = groupTail->next;
                if (!groupTail) {
                    // Less than k nodes left, leave them as they are
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }
            
            // Keep track of the node starting the next group
            ListNode* nextGroupHead = groupTail->next;
            
            // Step 2: Reverse the current k-group
            ListNode* prev = nextGroupHead; // Connect the tail of reversed group to nextGroupHead
            ListNode* tempCurr = prevGroupTail->next;
            ListNode* groupHead = prevGroupTail->next; // Will become the new tail after reversal
            
            while (tempCurr != nextGroupHead) {
                ListNode* nextNode = tempCurr->next;
                tempCurr->next = prev;
                prev = tempCurr;
                tempCurr = nextNode;
            }
            
            // Step 3: Connect previous group's tail to the new head of reversed segment
            prevGroupTail->next = groupTail;
            
            // Move prevGroupTail pointer to the tail of our newly reversed segment
            prevGroupTail = groupHead;
            curr = nextGroupHead;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
