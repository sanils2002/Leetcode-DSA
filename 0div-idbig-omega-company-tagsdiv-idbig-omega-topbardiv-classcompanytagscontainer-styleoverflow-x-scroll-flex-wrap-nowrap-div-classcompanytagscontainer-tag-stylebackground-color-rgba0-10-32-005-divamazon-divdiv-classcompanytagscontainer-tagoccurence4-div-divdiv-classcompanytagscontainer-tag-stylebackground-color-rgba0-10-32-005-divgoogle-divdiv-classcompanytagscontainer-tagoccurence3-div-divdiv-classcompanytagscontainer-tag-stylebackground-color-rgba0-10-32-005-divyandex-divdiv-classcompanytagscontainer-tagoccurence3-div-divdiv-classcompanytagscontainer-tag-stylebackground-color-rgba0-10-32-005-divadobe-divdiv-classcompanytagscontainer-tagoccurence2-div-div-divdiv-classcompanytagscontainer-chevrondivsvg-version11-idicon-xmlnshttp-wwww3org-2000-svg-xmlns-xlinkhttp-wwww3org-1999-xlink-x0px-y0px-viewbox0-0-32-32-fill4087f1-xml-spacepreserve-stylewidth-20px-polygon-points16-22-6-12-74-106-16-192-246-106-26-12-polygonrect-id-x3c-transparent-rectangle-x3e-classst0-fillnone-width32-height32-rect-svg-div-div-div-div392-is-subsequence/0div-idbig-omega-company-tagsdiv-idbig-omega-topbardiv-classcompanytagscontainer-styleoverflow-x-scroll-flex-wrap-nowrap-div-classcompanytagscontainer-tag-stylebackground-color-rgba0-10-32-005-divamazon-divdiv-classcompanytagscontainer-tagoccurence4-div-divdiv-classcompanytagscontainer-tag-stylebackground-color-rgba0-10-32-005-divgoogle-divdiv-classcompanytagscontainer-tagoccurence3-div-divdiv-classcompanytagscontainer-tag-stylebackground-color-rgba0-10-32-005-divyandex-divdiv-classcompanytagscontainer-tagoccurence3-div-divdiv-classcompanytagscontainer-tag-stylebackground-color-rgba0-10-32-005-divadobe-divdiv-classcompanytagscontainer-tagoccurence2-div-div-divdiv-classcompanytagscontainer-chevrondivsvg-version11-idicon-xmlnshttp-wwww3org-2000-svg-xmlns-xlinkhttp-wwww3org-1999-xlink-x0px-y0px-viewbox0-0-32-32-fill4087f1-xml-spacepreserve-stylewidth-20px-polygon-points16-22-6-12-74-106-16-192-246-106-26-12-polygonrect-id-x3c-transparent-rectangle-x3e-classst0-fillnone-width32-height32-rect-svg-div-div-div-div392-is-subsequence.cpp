class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> q;
        int cnt = 0;
    
        // push the string t in queue;
        for(int i = 0; i < t.size(); i++) {
            q.push(t[i]);
        }
    
        int i = 0;
        // traverse throgh the entire queue
        while(!q.empty()) {
            // check if the ith element in s is equal to front element
            if(s[i] == q.front()) {
                cnt++;
                i++;
            }
        
            // pop element of queue after each iteration
            q.pop();
        }
    
        // check for the cnt length
        if(cnt == s.size())
            return true;
        else
            return false;
    }
};