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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> ans;
        vector<double> v;
        if(NULL == root)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int idx = 0 ; idx < sz ; idx++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node -> val);
                
                if(NULL != node -> left)
                    q.push(node -> left);
                if(NULL != node -> right)
                    q.push(node -> right);
            }
            ans.push_back(temp);
        }
        
        for(auto &val : ans) {
            double sum = 0;
            for(auto &x : val) {
                sum += x;
            }
            sum /= val.size();
            v.push_back(sum);
        }
        
        return v;
    }
};