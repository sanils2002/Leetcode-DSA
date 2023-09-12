class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
    
        int minIndex = 0;
        int maxIndex = 0;
    
        // Find the index of the minimum and maximum elements in the array.
        for(int i = 0; i < n; ++i) {
            if(nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if(nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
    
        //When removed from front only
        int front = max(maxIndex, minIndex) + 1;
		
		//When removed from back only
        int back = n - min(minIndex, maxIndex);
		
		//When removed from both front and back
        int frontBack = (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex));
		
        return min(min(front, back), frontBack);
    }
};