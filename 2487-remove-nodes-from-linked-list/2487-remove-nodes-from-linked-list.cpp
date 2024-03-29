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
    ListNode* reverseList(ListNode* head) {
        if(NULL == head or NULL == head -> next) return head;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr -> next;
        
        while(curr) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(curr) next = curr -> next;
        }
        
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        for(auto p = head ; NULL != p && NULL != p->next ;) {
        if (p -> val > p -> next -> val)
            p -> next = p -> next -> next;
        else
            p = p -> next;
        }
    return reverseList(head);
    }
};