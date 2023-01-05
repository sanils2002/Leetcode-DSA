class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals by increasing order of start time
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });

        // Keep track of the end time of the previous interval
        int end = intervals[0][1];
        int count = 0;

        for(int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the previous one, we need to remove one of them
            if(intervals[i][0] < end) {
                count++;
                // Remove the interval with the larger end time
                if(intervals[i][1] < end) {
                    end = intervals[i][1];
                }
            }
            
            // If the current interval does not overlap with the previous one, update the end time
            else {
                end = intervals[i][1];
            }
        }

        return count;
    }
};