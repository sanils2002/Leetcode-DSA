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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head;
        int prev = head -> val;
        ListNode *pre = temp;
        temp = temp -> next;
        
        while(temp != nullptr) {
            int curr = temp -> val;
            int num = __gcd(curr, prev);
            pre -> next = new ListNode(num);
            pre = pre -> next;
            pre -> next = temp;
            pre = temp;
            temp = temp -> next;
            prev = curr;
        }
        
        return head;
    }
};