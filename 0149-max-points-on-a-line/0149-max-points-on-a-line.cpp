class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) {
            return n;
        }
        
        int pts = INT_MIN;
        for(int idx = n - 1 ; idx >= 2 ; idx--) {
            int x1 = points[idx][0], y1 = points[idx][1];
            for(int jdx = idx - 1 ; jdx >= 1 ; jdx--) {
                int x2 = points[jdx][0] - x1, y2 = points[jdx][1] - y1;
                int cnt = 2;
                for(int kdx = jdx - 1 ; kdx >= 0 ; kdx--) {
                    if((points[kdx][1] - y1)*x2 == (points[kdx][0] - x1)*y2)
                        cnt++;
                    pts = max(pts, cnt);
                }
            }
        }
        
        return pts;
    }
};