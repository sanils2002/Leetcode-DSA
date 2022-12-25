class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int idx = 1 ; idx < nums.size() ; idx++) {
            nums[idx] += nums[idx - 1];
        }
        vector<int> val;
        for(int num : queries) {
            int sum = 0;
            int idx = 0;
            for(idx = 0 ; idx < nums.size() ; idx++) {
                if(sum + nums[idx] > num)
                    break;
            }
            val.push_back(idx);
        }
        return val;
    }
};