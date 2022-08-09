class Solution {
private:
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> s;
        for(int idx = 0 ; idx < 3 ; idx++) {
            int x = points[idx][0], y = points[idx][1];
            for(int jdx = idx + 1 ; jdx < 4 ; jdx++) {
                int x1 = points[jdx][0], y1 = points[jdx][1];
                double dist = sqrt( (x - x1) * (x - x1) + (y - y1) * (y - y1) );
                if(0 == dist) {
                    return false;
                }
                s.insert(dist);
            }
        }
        
        return 2 == s.size();
    }
};