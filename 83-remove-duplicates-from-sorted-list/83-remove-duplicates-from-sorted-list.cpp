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
        ListNode *begin = head;
        while(begin && begin -> next) {
            ListNode *find = begin -> next;
            if(find -> val == begin -> val) {
                begin -> next = find -> next;
                delete find;
            }
            else {
                begin = find;
            }
        }
        
        return head;
    }
};