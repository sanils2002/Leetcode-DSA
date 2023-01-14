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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

    // Get the length of the list
    int length = 1;
    ListNode* current = head;
    while (current->next) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Find the new tail of the list, which is (length - k % length - 1)th node
    int new_tail = length - k % length - 1;
    current = head;
    for (int i = 0; i < new_tail; i++) {
        current = current->next;
    }

    // Update the head and tail of the list
    head = current->next;
    current->next = nullptr;
        
        return head;
    }
};