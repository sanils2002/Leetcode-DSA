class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> res;
        vector<int> v(n + 1, 0);
        int i = 1,j = 1;
        while(v[i] == 0) {
            v[i] = -1;
            i += (j * k);
            while(i > n)
                i -= n;
            j++;
        }
        
        for(int i = 1 ; i <= n ; i++) {
            if(v[i] != -1)
                res.push_back(i);
        }
        
        return res;

    }
};