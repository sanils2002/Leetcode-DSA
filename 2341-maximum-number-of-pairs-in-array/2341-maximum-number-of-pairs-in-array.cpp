class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(auto &num : nums) {
            mp[num]++;
        }
        
        int cnt = 0;
        for(auto &num : nums) {
            if(mp[num] % 2 == 0) {
                cnt += (mp[num] / 2);
                mp[num] = 0;
            }
            else {
                cnt += (mp[num] - 1) / 2;
                mp[num] = 1;
            }
        }
        
        ans.push_back(cnt);
        cnt = 0;
        for(auto &ip : mp) {
            if(ip.second == 1) {
                cnt++;
            }
        }
        ans.push_back(cnt);
        
        return ans;
    }
};