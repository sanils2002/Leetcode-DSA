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

// Comparator for min heap
struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a min heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Add the first node of each linked list to the min heap
        for(auto list : lists) {
            if(list != nullptr) {
                minHeap.push(list);
            }
        }
        
        // Create a dummy node as the head of the merged linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        // Merge the linked lists by removing the minimum node from the min heap
        while(!minHeap.empty()) {
            // Remove the minimum node from the min heap
            ListNode* node = minHeap.top();
            minHeap.pop();
            
            // Add the minimum node to the merged linked list
            curr->next = node;
            curr = curr->next;
            
            // Add the next node of the removed node to the min heap
            if(node->next != nullptr) {
                minHeap.push(node->next);
            }
        }
        
        // Return the head of the merged linked list
        return dummy->next;
    }
};