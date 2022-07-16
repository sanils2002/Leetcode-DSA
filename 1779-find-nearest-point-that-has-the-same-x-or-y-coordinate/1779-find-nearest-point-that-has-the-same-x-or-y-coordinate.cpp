class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1, min_dis = INT_MAX;
        for(int idx = points.size()-1 ;  idx >= 0 ; idx--) {
            if(x == points[idx][0] or y == points[idx][1]) {
                int dis = abs(x-points[idx][0]) + abs(y-points[idx][1]);
                if(min_dis >= dis) {
                    min_dis = dis;
                    index = idx;
                }
            }
        }
        return index;
    }
};