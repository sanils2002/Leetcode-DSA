class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> m;
        
        for(auto x : nums)
            m[x]++;
        
        sort(nums.begin(), nums.end());
        vector<int>::iterator ip;
        ip = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), ip));
        
        int tnSize = nums.size();
        vector<vector<int>> sanils2002;
        
        for(int idx = 0 ; idx < tnSize ; idx++) {
            int target = -nums[idx];
            
            int jdx = idx + 1, kdx = tnSize - 1;
            
            while(kdx > jdx) {
                if(target == nums[jdx] + nums[kdx]) {
                    sanils2002.push_back({nums[idx], nums[jdx], nums[kdx]});
                    jdx += 1;
                    kdx -= 1;
                }
                else if(target > nums[jdx] + nums[kdx])
                    jdx += 1;
                else 
                    kdx -= 1;
            }
            
            jdx = 0;
            while(jdx < tnSize) {
                if(idx != jdx and target == 2*nums[jdx] and m[nums[jdx]] >= 2)
                    sanils2002.push_back({nums[idx], nums[jdx], nums[jdx]});
                jdx += 1;
            }
        }
        
        if(m[0] >= 3) {
            sanils2002.push_back({0, 0, 0});
        }
        
        return sanils2002;
    }
};