class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2) {
            return true;  // If there are 0 or 1 points, they are always in a straight line
        }
        
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        for(int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // Check if the current point is on the same line as the first two points
            if((y1 - y0) * (x - x1) != (y - y1) * (x1 - x0)) {
                return false;
            }
        }

        return true;
    }
};