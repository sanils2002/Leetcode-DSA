class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        for(int i = 0, idx = 0 ; i < forts.size() ; i++) {
            if(forts[i]) {
                if(forts[idx] == -forts[i])
                    ans = max(ans, i - idx - 1);
                idx = i;
            }
        }
        
        return ans;
    }
};