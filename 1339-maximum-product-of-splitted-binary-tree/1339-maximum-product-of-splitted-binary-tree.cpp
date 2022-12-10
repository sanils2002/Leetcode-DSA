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
long long ans = 0, totalSum = 0;
private:
    int dfs(TreeNode* root) {
        if(NULL == root)
            return 0;
        
        int currSum = dfs(root -> left) + dfs(root -> right) + root -> val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        dfs(root); // Then dfs in post order to calculate sum of each subtree and its complement
        return ans % int(1e9+7);
    }
};