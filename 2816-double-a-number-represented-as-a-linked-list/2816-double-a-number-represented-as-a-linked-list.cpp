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
    ListNode* doubleIt(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // Reverse the original list
        ListNode* reversed = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* temp = current->next;
            current->next = reversed;
            reversed = current;
            current = temp;
        }

        // Double the reversed list
        int carry = 0;
        current = reversed;
        while (current) {
            int newVal = current->val * 2 + carry;
            current->val = newVal % 10;
            carry = newVal / 10;

            if (!current->next && carry > 0) {
                current->next = new ListNode(carry);
                break;
            }

            current = current->next;
        }

        // Reverse the list again to restore the original order
        ListNode* finalList = nullptr;
        while (reversed) {
            ListNode* temp = reversed->next;
            reversed->next = finalList;
            finalList = reversed;
            reversed = temp;
        }

        return finalList;
    }
};