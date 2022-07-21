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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* link = new ListNode(0);
        link -> next = head;
        ListNode* prev = link; // head on prev
        
        for(int idx = 0 ; idx < left - 1 ; idx++) {
            prev = prev -> next;
        }
        
        ListNode* curr = prev -> next;
        for(int idx = 0 ; idx < right - left ; idx++) {
            ListNode* future = curr -> next;
            curr -> next = future -> next;
            future -> next = prev -> next;
            prev -> next = future;
        }
        
        return link -> next;
    }
};