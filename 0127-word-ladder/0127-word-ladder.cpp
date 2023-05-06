class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) {
            return 0; // endWord is not in the dictionary
        }
    
        unordered_set<string> visited; // to keep track of visited words
        queue<string> q; // a queue for the breadth-first search
        q.push(beginWord);
        visited.insert(beginWord);
        
        int level = 1; // the level of the BFS
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if(curr == endWord) {
                    return level; // found the endWord
                }
                
                for(int j = 0; j < curr.length(); j++) {
                    char originalChar = curr[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c; // change one character
                        if(dict.find(curr) != dict.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = originalChar; // change it back for the next iteration
                }
            }
            
            level++; // increment the level
        }
    
        return 0;
    }
};