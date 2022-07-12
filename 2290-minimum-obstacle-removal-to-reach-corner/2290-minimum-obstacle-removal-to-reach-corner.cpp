class Solution {
private:
    typedef pair<int, pair<int, int>> piii;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    #define f1(idx, a, n) for(int idx = a ; idx < n ; idx++)
    
    int dijkstra(vector<vector<int>> &nums, int key1, int key2) {
        int cut[key1][key2];
        f1(idx, 0, key1) {
            f1(jdx, 0, key2)
                cut[idx][jdx] = INT_MAX;
        }
        cut[0][0] = 0;
        
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0,{0, 0}});
        
        while(!pq.empty()) {
            piii ip = pq.top();
            pq.pop();
            int tar1 = ip.second.first;
            int tar2 = ip.second.second;
            if(tar1 == key1 - 1 and tar2 == key2 - 1)
                return ip.first;
            f1(idx, 0, 4) {
                int ntar1 = tar1 + dx[idx];
                int ntar2 = tar2 + dy[idx];
                if(ntar1 < 0 or ntar2 < 0 or ntar1 >= key1 or ntar2 >= key2)
                    continue;
                if(cut[ntar1][ntar2] > cut[tar1][tar2] + nums[ntar1][ntar2]) {
                    cut[ntar1][ntar2] = cut[tar1][tar2] + nums[ntar1][ntar2];
                    pq.push({cut[ntar1][ntar2], {ntar1, ntar2}});
                }
            }
        }
        
        return cut[key1-1][key2-1];
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int sanils2002 = grid.size();
        int sanilss_23 = grid[0].size();
        return dijkstra(grid, sanils2002, sanilss_23);
    }
};