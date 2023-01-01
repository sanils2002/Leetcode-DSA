class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans=1;
        string a = "";
        
        for(int i=0 ; i < s.size() ; i++){
            if((s[i]-'0') > k) 
                return -1;
            a += s[i];
            long long  x = stoll(a);
            if(x > k){
                ans += 1;
                a = "";
                a += s[i];
            }
        }
        
        return ans;
    }
};