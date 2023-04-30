class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> v(n * m);
        
        for(int i = 0 ; i < n * m ; i++)
            v[arr[i] - 1] = i;
        
        vector<int> r(n), c(m);
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                r[i] = max(r[i], v[mat[i][j] - 1]);
                c[j] = max(c[j], v[mat[i][j] - 1]);
            }
        }
        
        return min(*min_element(r.begin(), r.end()), *min_element(c.begin(), c.end()));
    }
};