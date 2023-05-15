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
private:
    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* cur = begin->next;
        ListNode* prev = begin;
        ListNode* first = cur;
        
        while(cur != end) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        begin->next = prev;
        first->next = cur;
        return first;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) {
            return head;
        }
    
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int i = 0;
        while(head) {
            i++;
            if(i % k == 0) {
                cur = reverse(cur, head->next);
                head = cur->next;
            } 
            else {
                head = head->next;
            }
        }
    
        return dummy->next;
    }
};