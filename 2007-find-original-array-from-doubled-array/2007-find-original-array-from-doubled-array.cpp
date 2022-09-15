class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        map<int, int> mp;
        
        for(int idx = 0 ; idx < n ; idx++) {
            mp[changed[idx]]++;
        }
        
        if(1 == n)
            return {};
        
        vector<int> v;
        for(auto &ip : mp) {
            int x = ip.first;
            
            if(0 == mp[x])
                continue;
            
            while(mp[x] > 0) {
                v.push_back(x);
                mp[x]--;
                mp[2*x]--;
            }
            
            if(mp[x] < 0)
                return {};
        }
        
        return v;
    }
};