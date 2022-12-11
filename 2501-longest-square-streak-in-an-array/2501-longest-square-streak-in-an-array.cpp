class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 0;
        
        set<int> s;
        for(auto n : nums) {
            s.insert(n);
        }
        
        for(auto n : nums) {
            long int t = n;
            int c = 0;
            while(s.find(t) != s.end()) {
                c++;
                s.erase(t);
                t = t * t;
            }
            
            ans = max(ans, c);
        }
        
        return ans < 2 ? -1 : ans;
    }
};