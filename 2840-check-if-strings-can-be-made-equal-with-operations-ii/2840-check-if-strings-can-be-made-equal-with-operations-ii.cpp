class Solution {
private:
     string oddeven(string s) {
        string odd = "";
        string even = "";
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(i%2) 
                odd+=s[i];
            else 
                even+=s[i];
        }
         
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        return odd + even;
    }
public:
    bool checkStrings(string s1, string s2) {
        string a = oddeven(s1);
        string b = oddeven(s2);
        
        return a == b;
    }
};