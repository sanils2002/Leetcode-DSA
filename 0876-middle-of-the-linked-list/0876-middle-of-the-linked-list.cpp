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
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head;
        ListNode* vertex = head;
        while(NULL != vertex && NULL != vertex -> next) {
            middle = middle -> next;
            vertex = vertex -> next -> next;
        }
        return middle;
    }
};