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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Convert linked list to vector
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        // Build BST from sorted vector
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};