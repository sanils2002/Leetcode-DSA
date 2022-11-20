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
    void check(TreeNode*root, vector<int> &ans) {
        if(NULL == root)
            return;
        check(root -> left, ans);
        ans.push_back(root -> val);
        check(root -> right, ans);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> ans;
        check(root, ans);
        
        vector<vector<int>>sol;
        for(int k=0 ; k < q.size() ; k++) {
            vector<int> te(2);
            auto it=lower_bound(ans.begin(),ans.end(), q[k]);
            if(it==ans.begin()) {
                if(*it==q[k]) {
                    te[0]=*it;
                }
                else {
                    te[0]=-1;
                }
            }
            else {
                if(it==ans.end()) {
                    --it;
                    te[0] =* it;
                }
                
                else if(*it==q[k]) {
                       te[0]=q[k];
                }
                else{
                    --it;
                    te[0]=*it;
                }
                
             }
            
             auto j=lower_bound(ans.begin(),ans.end(),q[k]);
             if(j==ans.end()) {
                 te[1]=-1;
             }
             else {
                 te[1]=*j;
             }
             sol.push_back(te);
            
         }
        return sol;
    }
};