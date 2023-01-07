class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1 && k % 2 == 1) 
            return -1;  // if size is 1 and k odd stack will be empty
        int n = nums.size();
        int mx = 0, mn = min(k - 1, n);
        for(int i = 0 ; i < mn ; i++)  // finding the max element from first k-1 elelment or len -1 if len is less than k
            mx = max(mx, nums[i]);
        if(k < n)  // check for scenario where we don't have to put back Max out of k-1 element
            mx = max(mx, nums[k]);
  
        return mx;
    }
};