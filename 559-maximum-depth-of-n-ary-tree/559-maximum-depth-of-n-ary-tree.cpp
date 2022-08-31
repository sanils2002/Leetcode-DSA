/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(NULL == root)
            return 0;
        int depth = 0;
        
        for(int idx = 0 ; idx < root -> children.size() ; idx++) {
            int pass = maxDepth(root -> children[idx]);
            depth = max(depth, pass);
        }
        
        return depth + 1;
    }
};