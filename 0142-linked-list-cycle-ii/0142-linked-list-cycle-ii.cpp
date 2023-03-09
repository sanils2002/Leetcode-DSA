/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> set;
//         while(head != NULL) {
//             if(set.find(head) != set.end()) {
//                 return head;
//             } 
//             else {
//                 set.insert(head);
//             }
//             head = head->next;
//         }
        
//         return NULL;
        
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
    
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode *p1 = head;
                ListNode *p2 = slow;
                while(p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
    
        return NULL;

    }
};