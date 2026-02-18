/*
Time Complexity:
- We traverse the list once.
- Each node is visited once.
Overall: O(n)

Space Complexity:
- No extra data structures used.
- Only a few pointer variables.
Overall: O(1)
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // Edge case
        if(head == NULL || head->next == NULL)
            return head;
        
        // Dummy node to simplify head swap
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        
        while(prev->next != NULL && prev->next->next != NULL) {
            
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev pointer forward
            prev = first;
        }
        
        return dummy.next;
    }
};
