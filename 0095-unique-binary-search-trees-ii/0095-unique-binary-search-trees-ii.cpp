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
    vector<TreeNode*> generate(int st, int en) {
        vector<TreeNode*> v;
        if(st > en) {
            v.push_back(NULL);
            return v;
        }

        if(st == en) {
            v.push_back(new TreeNode(st));
            return v;
        }

        for(auto i = st ; i <= en ; i++) {
            vector<TreeNode *> lft = generate(st, i-1);
            vector<TreeNode *> rgt = generate(i+1, en);

            for(auto l : lft) {
                for(auto r : rgt) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        
        return v;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>();
        else 
            return generate(1, n);
    }
};