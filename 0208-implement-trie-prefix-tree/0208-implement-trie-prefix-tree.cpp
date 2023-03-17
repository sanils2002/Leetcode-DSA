class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
        TrieNode() : isWord(false) {}
    };
    TrieNode* root;
    
    TrieNode* searchNode(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return nullptr;
            }
            curr = curr->children[c];
        }
        return curr;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr && node->isWord);
    }
    
    bool startsWith(string prefix) {
        return (searchNode(prefix) != nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */