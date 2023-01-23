class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in_degree(N + 1);
        vector<int> out_degree(N + 1);

        for(auto t : trust) {
            out_degree[t[0]]++;
            in_degree[t[1]]++;
        }

        for(int i = 1; i <= N; i++) {
            if(out_degree[i] == 0 && in_degree[i] == N - 1) {
                return i;
            }
        }
    
        return -1;
    }
};