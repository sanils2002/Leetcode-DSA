class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, en = n - 1;
        while(st <= en) {
            int mid = st + (en - st) / 2;
            if(target == nums[mid])
                return mid;
            else if(nums[en] > nums[mid]) {
                if(target > nums[mid] and target <= nums[en])
                    st = mid + 1;
                else
                    en = mid - 1;
            }
            else {
                if(target < nums[mid] and target >= nums[st])
                    en = mid - 1;
                else
                    st = mid + 1;
            }
        }
        
        return -1;
    }
};