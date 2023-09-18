class Solution {
private:
    // Custom comparator function to sort rows based on the number of soldiers
    static bool compareRows(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first != b.first) {
            return a.first < b.first; // Sort by the number of soldiers
        }
        return a.second < b.second; // If soldiers are equal, sort by row index
}
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> rows; // Store pairs (number of soldiers, row index)

        for(int i = 0; i < m; ++i) {
            int count = 0;
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 1) {
                    count++;
                } 
                else {
                    break; // Rows are sorted, so we can break early if we find 0
                }
            }
            rows.push_back({count, i});
        }

        // Sort the rows based on custom comparator function
        sort(rows.begin(), rows.end(), compareRows);

        vector<int> result;
        for(int i = 0; i < k; ++i) {
            result.push_back(rows[i].second); // Push row indices of the weakest rows
        }

        return result;
    }
};