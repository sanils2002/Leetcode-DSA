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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
    
        // Calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while(current != nullptr) {
            length++;
            current = current->next;
        }
    
        // Calculate the average length and the number of extra nodes
        int avgLength = length / k;
        int extraNodes = length % k;
    
        current = head;
        ListNode* prev = nullptr;
    
        for(int i = 0; i < k; i++) {
            result.push_back(current);
            int partLength = avgLength + (i < extraNodes ? 1 : 0);
        
            for(int j = 0; j < partLength; j++) {
                prev = current;
                current = current->next;
            }
        
            if(prev != nullptr) {
                prev->next = nullptr; // Terminate the current part
            }
        }
    
        return result;
    }
};