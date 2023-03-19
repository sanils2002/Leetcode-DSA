class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool searchHelper(string word, TrieNode* node) {
        TrieNode* curr = node;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto it : curr->children) {
                    if (searchHelper(word.substr(i+1), it.second)) {
                        return true;
                    }
                }
                return false;
            }
            if (!curr->children.count(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isWord;
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }
};
