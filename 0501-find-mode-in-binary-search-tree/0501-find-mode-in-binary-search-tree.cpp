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
    void calculateFrequency(TreeNode* node, unordered_map<int, int>& freq, int& maxFreq) {
        if(node == nullptr) {
            return;
        }

        calculateFrequency(node->left, freq, maxFreq);
        freq[node->val]++;
        maxFreq = max(maxFreq, freq[node->val]);
        calculateFrequency(node->right, freq, maxFreq);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        vector<int> modes;

        // Step 1: Calculate the frequency of each element in the BST
        calculateFrequency(root, freq, maxFreq);

        // Step 2: Find all elements with maximum frequency (modes)
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second == maxFreq) {
                modes.push_back(it->first);
            }
        }

        return modes;
    }
};