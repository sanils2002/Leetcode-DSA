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
    ListNode* head;
    Solution(ListNode* h) {
        head = h;
        srand(time(NULL)); // initialize random seed
    }
    
    int getRandom() {
        ListNode* node = head;
        int count = 1;
        int result = node->val;
        while(node != NULL) {
            if(rand() % count == 0) {
                result = node->val;
            }
            count++;
            node = node->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */