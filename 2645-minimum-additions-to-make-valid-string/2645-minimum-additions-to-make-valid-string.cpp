class Solution {
public:
    int addMinimum(string word) {
        int n = word.length(); 
        int ans = 0; 
        int i = 0; 
        while(i < n){ 
            string s1 = word.substr(i, 3); 
            string s2 = word.substr(i, 2); 

            if(s1 == "abc") { 
              i += 3; 
            } 
            else if(s2 == "ab" or s2 == "ac" or s2 == "bc") { 
                ans += 1; 
                i+=2; 
            } 
            else { 
                ans += 2; 
                i += 1; 
            } 
        }
        
        return ans; 
    }
};