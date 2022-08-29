class Solution {
public:
    int minimumSum(int num) {
        vector<int> v(4);
        
        for(int idx = 0 ; idx < 4 ; idx++) {
            v[idx] += num % 10;
            num /= 10;
        }
        
        sort(v.begin(), v.end());
        
        return ((v[0]*10 + v[2]) + (v[1]*10 + v[3]));
        
    }
};