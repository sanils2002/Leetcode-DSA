class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        //vector<vector<int>> diff;
        int m = grid.size(), n = grid[0].size();
        vector<int> oner(m, 0), onec(n, 0), zeror(m, 0), zeroc(n, 0);
        
        for(int idx = 0 ; idx < m ; idx++) {
            for(int jdx = 0 ; jdx < n ; jdx++) {
                if(1 == grid[idx][jdx]){oner[idx] += 1; onec[jdx] += 1;}
                else{zeror[idx] += 1; zeroc[jdx] += 1;}
            }
        }
        
        // for(auto idx = 0 ; idx < grid[0].size() ; idx++) {
        //     for(auto jdx = 0 ; jdx < grid.size() ; jdx++) {
        //         if(1 == grid[idx][jdx])
        //             onec[idx]++;
        //         else
        //             zeroc[idx]++;
        //     }
        // }
        
        for(int idx = 0 ; idx < m ; idx++) {
            for(int jdx = 0 ; jdx < n ; jdx++) {
                grid[idx][jdx] = oner[idx] + onec[jdx] - zeror[idx] - zeroc[jdx];
            }
        }
        
        return grid;
    }
};