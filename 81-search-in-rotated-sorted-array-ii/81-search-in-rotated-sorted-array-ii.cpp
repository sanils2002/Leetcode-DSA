class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, en = n - 1;
        while(st <= en) {
            int mid = st + (en - st) / 2;
            if(target == nums[mid])
                return true;
            if((nums[st] == nums[mid]) && (nums[en] == nums[mid]))
                st++, en--;
            else if(nums[st] <= nums[mid]) {
                if(target < nums[mid] and nums[st] <= target)
                    en = mid - 1;
                else
                    st = mid + 1;
            }
            else {
                if(target > nums[mid] and target <= nums[en])
                    st = mid + 1;
                else
                    en = mid - 1;
            }
        }
        
        return false;
    }
};