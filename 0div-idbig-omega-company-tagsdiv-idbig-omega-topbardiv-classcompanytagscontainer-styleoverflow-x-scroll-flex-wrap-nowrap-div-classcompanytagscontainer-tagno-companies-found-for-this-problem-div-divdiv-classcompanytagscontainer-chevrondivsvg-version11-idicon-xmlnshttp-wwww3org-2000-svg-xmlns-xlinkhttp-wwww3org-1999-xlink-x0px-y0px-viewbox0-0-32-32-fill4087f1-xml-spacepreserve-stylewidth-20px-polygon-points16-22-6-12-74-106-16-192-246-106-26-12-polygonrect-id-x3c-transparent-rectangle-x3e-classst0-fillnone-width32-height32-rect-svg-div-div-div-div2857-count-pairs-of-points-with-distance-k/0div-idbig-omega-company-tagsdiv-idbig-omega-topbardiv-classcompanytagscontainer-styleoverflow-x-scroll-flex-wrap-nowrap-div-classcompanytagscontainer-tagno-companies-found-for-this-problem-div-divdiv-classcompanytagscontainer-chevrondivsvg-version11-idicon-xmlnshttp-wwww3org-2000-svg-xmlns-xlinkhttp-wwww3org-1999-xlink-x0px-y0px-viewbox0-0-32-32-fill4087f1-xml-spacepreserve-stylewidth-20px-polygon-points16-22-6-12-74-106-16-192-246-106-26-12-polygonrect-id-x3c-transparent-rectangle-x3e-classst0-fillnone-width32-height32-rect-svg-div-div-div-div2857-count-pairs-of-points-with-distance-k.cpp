class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans = 0;
        map<pair<int, int>, int> mp;
        for(auto it : coordinates) {
            int x = it[0];
            int y = it[1];
            
            for(int i = 0 ; i <= k ; i++) {
                int a = i;
                int b = k - a;
                
                int x2 = a ^ x;
                int y2 = b ^ y;
                
                if(mp.find({x2, y2}) != mp.end()) {
                    ans += mp[{x2, y2}];
                }
            }
            mp[{x, y}]++;
        }
        return ans;
    }
};