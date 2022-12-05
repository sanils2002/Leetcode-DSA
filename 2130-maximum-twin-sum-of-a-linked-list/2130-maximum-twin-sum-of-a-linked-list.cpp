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
    int pairSum(ListNode* head) {
        int n = 0;
        int ans = 0;
        
        ListNode* st = head;
        ListNode* en = head;
        stack<ListNode*> s;
        
        while(en) {
            n++;
            s.push(en);
            en = en -> next;
        }
        
        while(s.size() > n / 2) {
            en = s.top();
            ans = max(ans, st -> val + en -> val);
            s.pop();
            st = st -> next;
        }
        
        return ans;
    }
};