class Solution {
private:
    const int mod = pow(10, 9) + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> result(queries.size());
        vector<int> powers;
        int x = n;
        while(x > 0) {
            int highestPower = log2(x);
            int pow = 1 << highestPower;
            x -= pow;
            powers.insert(powers.begin(), pow);
        }
        
        for(int j = 0; j < queries.size(); j++) {
            int start = queries[j][0];
            int end = queries[j][1];
            long long r = 1;
            for(int i = start; i <= end; i++) {
                r = (r * powers[i]) % mod;
            }
            result[j] = r % mod;
        }
        
        return result;
    }
};