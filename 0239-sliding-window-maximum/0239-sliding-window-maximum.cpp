class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int idx = 0 ; idx < nums.size() ; idx++){
            if(!dq.empty() && dq.front() == idx - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[idx])
                dq.pop_back();
            dq.push_back(idx);
            if(idx >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans; 
    }
};