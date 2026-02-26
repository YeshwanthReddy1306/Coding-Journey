class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
            // Find kth node
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if (kth == nullptr) break;  // not enough nodes

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous group to reversed group
            prevGroupEnd->next = kth;

            // Move prevGroupEnd forward
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};