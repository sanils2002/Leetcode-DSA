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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *node1 = NULL, *node2 = NULL;
        for(auto ip = head ; ip != NULL ; ip = ip -> next) {
            node2 = (NULL == node2) ? NULL : node2 -> next;
            if(0 == --k) {
                node1 = ip;
                node2 = head;
            }
        }
        swap(node1 -> val, node2 -> val);
        return head;
    }
};