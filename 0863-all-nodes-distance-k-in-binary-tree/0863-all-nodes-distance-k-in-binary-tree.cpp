/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildParentMap(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if(node->left) {
            parentMap[node->left] = node;
            buildParentMap(node->left, parentMap);
        }
        if(node->right) {
            parentMap[node->right] = node;
            buildParentMap(node->right, parentMap);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Build a parent map to track the parent of each node
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, parentMap);

        // Step 2: Perform a breadth-first search starting from the target node
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int currDist = 0;
        while(!q.empty()) {
            int size = q.size();
            if (currDist == k) {
                vector<int> result;
                for(int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    result.push_back(node->val);
                }
                return result;
            }

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                TreeNode* parent = parentMap[node];
                if(parent && !visited[parent]) {
                    visited[parent] = true;
                    q.push(parent);
                }
            }
            currDist++;
        }

        return {};  // No nodes found at distance k
    }
};