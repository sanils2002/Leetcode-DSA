/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *pointer = head;
        ListNode *tail = head;
        while(NULL != tail && NULL != tail -> next) {
            pointer = pointer -> next;
            tail = tail -> next -> next;
            if(tail == pointer)
                return true;
        }
        return false;
    }
};