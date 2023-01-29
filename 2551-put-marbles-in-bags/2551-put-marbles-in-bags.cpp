class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        if(k == 1 || k == w.size()) 
            return 0;
        
        long long ans = 0;
        long long ans2 = 0;
        k--;

        vector<long long>res, res2;

        for(long long i = 0 ; i < w.size() - 1 ; i++) {
            res.push_back(w[i] + w[i + 1]);
            res2.push_back(w[i] + w[i + 1]);
        }

        sort(res.begin(), res.end() , greater<long long>());
        sort(res2.begin(), res2.end());


        for(long long i = 0 ; i < k ;i++)
            ans += res[i];
        for(long long i = 0 ; i < k ; i++) 
            ans2 += res2[i];


        return ans - ans2;
    }
};