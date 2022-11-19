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
    ListNode* oddEvenList(ListNode* head) {
        if(NULL == head)
            return {};
        
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = head -> next;
        while(NULL != even and NULL != even -> next) {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            
            odd = odd -> next;
            even = even -> next;
        }
        
        odd -> next = evenHead;
        return head;
    }
};