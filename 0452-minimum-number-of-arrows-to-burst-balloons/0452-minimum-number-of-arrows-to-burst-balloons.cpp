class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // If there are no balloons, we don't need to shoot any arrows.
        if(points.empty()) {
            return 0;
        }

        // Sort the balloons by the start of their horizontal diameter.
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        // Initialize the minimum number of arrows to 1.
        int minArrows = 1;
        // Initialize the end of the horizontal diameter of the first balloon.
        int end = points[0][1];

        // Iterate through the rest of the balloons.
        for(int i = 1; i < points.size(); i++) {
            // If the start of the horizontal diameter of the current balloon is greater
            // than the end of the horizontal diameter of the previous balloon, we need
            // to shoot a new arrow.
            if (points[i][0] > end) {
                minArrows++;
                end = points[i][1];
            } 
            else {
                // If the start of the horizontal diameter of the current balloon is less
                // than or equal to the end of the horizontal diameter of the previous
                // balloon, we can use the same arrow to burst both balloons.
                // Update the end of the horizontal diameter to the minimum of the two.
                end = min(end, points[i][1]);
            }
        }

        return minArrows;
    }
};