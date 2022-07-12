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
    bool isPalindrome(ListNode* head) {
        ListNode* middle = head;
        ListNode* vertex = head -> next;
        
        while(vertex and vertex -> next) {
            middle = middle -> next;
            vertex = vertex -> next -> next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = middle;
        ListNode* next = NULL;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        middle -> next = NULL;
        
        while(head and prev) {
            if(head -> val != prev -> val) return false;
            head = head -> next;
            prev = prev -> next;
        }
        
        return true;
    }
};