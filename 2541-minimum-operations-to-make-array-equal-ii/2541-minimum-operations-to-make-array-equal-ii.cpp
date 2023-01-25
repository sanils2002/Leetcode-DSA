class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long small=0;
        long long large=0;
        for(int i = 0 ; i < nums1.size() ; i++) {   
            if(nums1[i] > nums2[i]) {   
                if(k == 0) 
                    return -1;
                if((nums1[i] - nums2[i]) < k or (nums1[i] - nums2[i])%k != 0) 
                    return -1;
                large += (nums1[i] - nums2[i]) / k;
                
            }
            else if(nums1[i] < nums2[i]) {  
                if(k == 0) 
                    return -1;
                if((nums2[i] - nums1[i]) < k or (nums2[i] - nums1[i])%k != 0) 
                    return -1;
                small += (nums2[i] - nums1[i]) / k;
            }
        }
        
        if(large != small) 
            return -1;
        return large;
    }
};