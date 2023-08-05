class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination(k, 0);
        int i = 0;
        while(i >= 0) {
            combination[i]++;
            if(combination[i] > n) {
                i--;
            } 
            else if (i == k - 1) {
                res.push_back(combination);
            } 
            else {
                i++;
                combination[i] = combination[i - 1];
            }
            // for(auto &x: combination)
            //     cout << x << " ";
            // cout << "\n";
        }

        return res;
    }
};