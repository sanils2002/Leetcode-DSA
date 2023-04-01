class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1;
        //int index = -1;
        
        while(st <= en) {
            int mid = st + (en - st) / 2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                st = mid + 1;
            else
                en = mid - 1;
        }
        
        return -1;
    }
};