class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<double> st;
        
        int sr = 0, en = nums.size() - 1;
        while(sr < en) {
            double avg = (nums[sr++] + nums[en--]) / 2.0;
            st.insert(avg);
            //sr++, en--;
        }
        return st.size();
    }
};