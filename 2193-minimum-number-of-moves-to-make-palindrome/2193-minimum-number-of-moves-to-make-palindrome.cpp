class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0, j = n - 1; i < j; ) {
            if(s[i] == s[j]) {
                i++; j--;
            } 
            else {
                int k = j - 1;
                while(k > i && s[k] != s[i]) 
                    k--;
                if(k == i) {
                    swap(s[i], s[i+1]);
                    cnt++;
                } 
                else {
                    while(k < j) {
                        swap(s[k], s[k+1]);
                        k++; cnt++;
                    }
                    i++; j--;
                }
            }
        }
    
        return cnt;
    }
};