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
    int dFS(TreeNode*root, int &sum) {
        if(NULL == root)
            return 1;
        int l = dFS(root -> left, sum);
        int r = dFS(root -> right, sum);
        
        if(0 == l or 0 == r) {
            sum += 1;
            return 2;
        }
        if(1 == l and 1 == r)
            return 0;
        if(2 == l or 2 == r)
            return 1;
        
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        int sum = 0;
        if(0 == dFS(root, sum))
            sum++;
        return sum;
    }
};