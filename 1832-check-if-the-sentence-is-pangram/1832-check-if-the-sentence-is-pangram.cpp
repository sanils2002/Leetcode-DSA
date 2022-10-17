class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int> s;
        for(auto &a : sentence) {
            s.insert(a);
        }
        
        return 26 == s.size();
    }
};