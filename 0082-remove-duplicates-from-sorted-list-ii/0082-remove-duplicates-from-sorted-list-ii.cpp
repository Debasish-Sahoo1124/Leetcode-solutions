/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // last node before duplicates
        ListNode* curr = head;

        while (curr != NULL) {
            // detect duplicates
            if (curr->next != NULL && curr->val == curr->next->val) {
                int val = curr->val;

                // skip all nodes with same value
                while (curr != NULL && curr->val == val) {
                    curr = curr->next;
                }

                // link prev to next non-duplicate
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
    
    
    
