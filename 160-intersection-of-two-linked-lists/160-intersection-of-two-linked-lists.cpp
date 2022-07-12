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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tail1 = headA;
        ListNode *tail2 = headB;
        
        while(tail1 != tail2) {
            if(NULL == tail1)
                tail1 = headB;
            else 
                tail1 = tail1 -> next;
            if(NULL == tail2)
                tail2 = headA;
            else
                tail2 = tail2 -> next;
        }
        
        return tail2;
    }
};