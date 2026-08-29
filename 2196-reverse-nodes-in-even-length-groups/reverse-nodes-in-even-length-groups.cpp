class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Pointer to track the node just before the current group
        ListNode* prevGroupEnd = head; 
        ListNode* curr = head->next;
        
        // Start expecting a group size of 2, since group 1 always has size 1 (odd)
        int expectedGroupSize = 2;
        
        while (curr != nullptr) {
            // Step 1: Count actual nodes available in the current group
            int actualGroupSize = 0;
            ListNode* temp = curr;
            while (temp != nullptr && actualGroupSize < expectedGroupSize) {
                actualGroupSize++;
                temp = temp->next;
            }
            
            // Step 2: If the actual group size is even, reverse it
            if (actualGroupSize % 2 == 0) {
                ListNode* nextGroupStart = temp; // 'temp' points to the start of the next group
                ListNode* prev = nextGroupStart;
                ListNode* groupNode = curr;
                
                // Standard linked list reversal for 'actualGroupSize' nodes
                for (int i = 0; i < actualGroupSize; ++i) {
                    ListNode* nextNode = groupNode->next;
                    groupNode->next = prev;
                    prev = groupNode;
                    groupNode = nextNode;
                }
                
                // Connect the previous group's end to the new head of this reversed group
                prevGroupEnd->next = prev;
                // Move prevGroupEnd to the tail of the newly reversed group (which was 'curr')
                prevGroupEnd = curr;
            } 
            // Step 3: If the actual group size is odd, skip reversal
            else {
                // Advance prevGroupEnd to the end of the current odd group
                for (int i = 0; i < actualGroupSize; ++i) {
                    prevGroupEnd = prevGroupEnd->next;
                }
            }
            
            // Move curr to the start of the next group
            curr = prevGroupEnd->next;
            // Increment the expected size for the next iteration
            expectedGroupSize++;
        }
        
        return head;
    }
};
