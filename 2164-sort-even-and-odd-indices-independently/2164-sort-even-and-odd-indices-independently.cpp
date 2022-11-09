class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(auto idx = 0 ; idx < nums.size() ; idx++) {
            if(idx & 1)
                odd.push_back(nums[idx]);
            else
                even.push_back(nums[idx]);
        }
        
        sort(odd.begin(), odd.end(), greater<int>()); //Descending Order
        sort(even.begin(), even.end());
        
        for(auto idx = 0 ; idx < nums.size() ; idx++) {
            if(idx & 1) {
                nums[idx] = odd[0];
                odd.erase(odd.begin());
            }
            else {
                nums[idx] = even[0];
                even.erase(even.begin());
            }
        }
        
        return nums;
    }
};