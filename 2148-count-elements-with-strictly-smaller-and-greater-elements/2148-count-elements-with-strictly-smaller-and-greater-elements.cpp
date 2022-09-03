class Solution {
public:
    int countElements(vector<int>& nums) {
        int flag1, flag2;
        int ele = 0;
        
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            flag1 = 0, flag2 = 0;
            for(int jdx = 0 ; jdx < nums.size() ; jdx++) {
                if(nums[jdx] > nums[idx])
                    flag1 = 1;
                if(nums[idx] > nums[jdx])
                    flag2 = 1;
            }        
            if(flag1 and flag2)
                ele++;
        }
        
        return ele;
    }
};