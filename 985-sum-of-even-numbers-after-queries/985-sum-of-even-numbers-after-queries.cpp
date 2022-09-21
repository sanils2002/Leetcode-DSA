class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evsm = 0;
        for(auto &num : nums)
            if(0 == num%2) {evsm += num;}
        
        vector<int> v(queries.size());
        for(int idx = 0 ; idx < queries.size() ; idx++) {
            int val = queries[idx][0], index = queries[idx][1];
            if(0 == nums[index] % 2)
                evsm -= nums[index];
            nums[index] += val;
            if(0 == nums[index] % 2)
                evsm += nums[index];
            v[idx] = evsm;
        }
        
        return v;
        
    }
};