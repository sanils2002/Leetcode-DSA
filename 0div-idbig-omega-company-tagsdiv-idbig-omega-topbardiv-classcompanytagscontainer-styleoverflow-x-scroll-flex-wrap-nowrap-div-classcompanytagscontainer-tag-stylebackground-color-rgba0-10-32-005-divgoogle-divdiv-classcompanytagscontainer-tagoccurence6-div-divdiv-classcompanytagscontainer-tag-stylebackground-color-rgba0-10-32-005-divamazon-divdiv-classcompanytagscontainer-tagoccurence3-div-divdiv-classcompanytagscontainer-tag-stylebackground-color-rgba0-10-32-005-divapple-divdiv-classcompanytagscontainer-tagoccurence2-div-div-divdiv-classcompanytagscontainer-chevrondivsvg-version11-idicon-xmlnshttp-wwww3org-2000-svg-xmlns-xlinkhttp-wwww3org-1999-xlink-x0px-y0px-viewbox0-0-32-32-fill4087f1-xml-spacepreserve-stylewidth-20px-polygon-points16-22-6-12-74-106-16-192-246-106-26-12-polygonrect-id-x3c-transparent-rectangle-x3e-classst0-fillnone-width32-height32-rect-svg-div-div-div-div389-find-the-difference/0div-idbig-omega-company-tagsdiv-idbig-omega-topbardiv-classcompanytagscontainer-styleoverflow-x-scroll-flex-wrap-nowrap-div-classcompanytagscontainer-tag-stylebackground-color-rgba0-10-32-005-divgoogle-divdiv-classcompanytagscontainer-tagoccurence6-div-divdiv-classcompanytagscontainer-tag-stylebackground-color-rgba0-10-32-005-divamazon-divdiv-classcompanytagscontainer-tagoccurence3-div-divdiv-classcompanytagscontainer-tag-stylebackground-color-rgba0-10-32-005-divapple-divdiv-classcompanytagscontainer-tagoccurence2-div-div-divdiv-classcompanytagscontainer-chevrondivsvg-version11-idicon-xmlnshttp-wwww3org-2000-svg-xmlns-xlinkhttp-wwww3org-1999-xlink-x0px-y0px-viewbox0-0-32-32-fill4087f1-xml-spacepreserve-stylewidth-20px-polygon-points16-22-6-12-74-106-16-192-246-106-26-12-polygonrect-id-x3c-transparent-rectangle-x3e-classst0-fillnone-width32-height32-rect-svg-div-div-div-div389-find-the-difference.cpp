class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
    
        for(char x : s) {
            result ^= x;
        }
        
        for(char x : t) {
            result ^= x;
        }
        
        return result;
    }
};