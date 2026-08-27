/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to help with edge cases
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        
        // Loop while there are at least two nodes to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Change pointers to swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move the prev pointer forward by two nodes
            prev = first;
        }
        
        return dummy.next;
    }
};
