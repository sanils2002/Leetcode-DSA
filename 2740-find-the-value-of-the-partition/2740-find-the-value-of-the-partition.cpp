class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            // Invalid input, at least two elements are required
            return -1;
        }

        // Sort the input array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Initialize the minimum partition value to a large number
        int minPartition = INT_MAX;

        // Iterate through each possible partition index
        for(int i = 1; i < n; i++) {
            // Calculate the partition value for the current partition index
            int partitionValue = abs(nums[i] - nums[i - 1]);

            // Update the minimum partition value if necessary
            minPartition = min(minPartition, partitionValue);
        }

        // Return the minimum partition value
        return minPartition;
    }
};