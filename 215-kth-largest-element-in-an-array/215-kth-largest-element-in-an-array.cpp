class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int idx = 0 ; idx < nums.size() ; idx++)
            pq.push(nums[idx]);
        int jdx = 1;
        int result;
        while(jdx <= k) {
            result = pq.top();
            pq.pop();
            jdx++;
        }
        return result;
    }
};