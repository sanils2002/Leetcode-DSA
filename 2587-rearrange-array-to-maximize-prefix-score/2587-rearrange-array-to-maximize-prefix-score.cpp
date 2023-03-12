class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long int pref = 0, res = 0;
        while(!nums.empty()) {
            pref += nums.back();
            nums.pop_back();
            if(pref > 0)
                res++;
        }
        
        return res;
    }
};