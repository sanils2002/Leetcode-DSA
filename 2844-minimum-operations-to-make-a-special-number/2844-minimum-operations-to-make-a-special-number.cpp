class Solution {
private:
    int check(string num, string tar) {
        int n = num.length();
        int cx = 0;
        int idx = 1;
        
        for(int i = n - 1 ; i >= 0 && idx >= 0 ; i--) {
            if(num[i]==tar[idx])
                idx--;
            else 
                cx++;
        }
        
        return idx < 0 ? cx : 101;
    }
public:
    int minimumOperations(string num) {
        int ans = num.find('0') != string::npos ? num.length() - 1 : num.length();
        ans = min({ans, check(num, "00"), check(num, "25"), check(num, "50"), check(num, "75")});
        return ans;
        
    }
};