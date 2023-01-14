class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long extra = accumulate(batteries.begin(), batteries.end() - n, 0LL);
        batteries.erase(batteries.begin(), batteries.end() - n);
        
        long long ans = 0, prefix = 0;
        for (int i = 0; i < batteries.size(); i++) {
            prefix += batteries[i];
            if(i + 1 < batteries.size() && (long long)batteries[i + 1] * (i + 1) - prefix > extra) { 
                return (prefix + extra) / (i + 1); 
            }
        }
        
        return (prefix + extra) / n;
    }
};