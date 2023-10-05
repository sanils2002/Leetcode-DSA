class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) {
            return result;
        }

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Step 1: Find candidates for majority elements.
        for(int num : nums) {
            if(candidate1 == num) {
                count1++;
            } 
            else if(candidate2 == num) {
                count2++;
            } 
            else if(count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } 
            else if(count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } 
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Count the occurrences of candidate elements.
        count1 = 0;
        count2 = 0;
        for(int num : nums) {
            if(num == candidate1) {
                count1++;
            } 
            else if(num == candidate2) {
                count2++;
            }
        }

        if(count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }
        if(count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }

        return result;
    }
};