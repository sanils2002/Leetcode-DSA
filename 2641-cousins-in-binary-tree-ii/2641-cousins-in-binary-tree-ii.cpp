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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            long long levsum = 0;
            int sz = que.size();
            vector<TreeNode*> vect;
            while(sz--){
                TreeNode* node = que.front();
                que.pop();
                long long cursum = 0;

                if(node -> left){
                    que.push(node -> left);
                    cursum += node -> left -> val;
                    vect.push_back(node -> left);
                }
                if(node -> right){
                    que.push(node -> right);
                    cursum += node -> right -> val;
                    vect.push_back(node -> right);
                }
                if(node -> left){
                    mp[node -> left] = cursum;
                }
                if(node -> right){
                    mp[node -> right] = cursum;
                }
                levsum += cursum;
            }
            
            for(TreeNode* child:vect){
                child -> val = levsum - (mp[child]);
            }
            
            vect.clear();
            levsum = 0;

        }
        root->val = 0;
        return root;
    }
};