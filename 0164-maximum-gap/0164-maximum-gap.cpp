class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }

        // Find the minimum and maximum elements in the array
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        // Compute the bucket size and the number of buckets
        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketCount = (maxNum - minNum) / bucketSize + 1;

        // Initialize the buckets with default values
        vector<int> minBucket(bucketCount, INT_MAX);
        vector<int> maxBucket(bucketCount, INT_MIN);

        // Assign each number to its corresponding bucket
        for(int num : nums) {
            int bucketIdx = (num - minNum) / bucketSize;
            minBucket[bucketIdx] = min(minBucket[bucketIdx], num);
            maxBucket[bucketIdx] = max(maxBucket[bucketIdx], num);
        }

        // Compute the maximum gap
        int maxGap = 0;
        int prevMax = minNum; // Store the maximum element of the previous non-empty bucket

        for(int i = 0; i < bucketCount; ++i) {
            if(minBucket[i] == INT_MAX && maxBucket[i] == INT_MIN) {
                // Skip empty buckets
                continue;
            }

            maxGap = max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};