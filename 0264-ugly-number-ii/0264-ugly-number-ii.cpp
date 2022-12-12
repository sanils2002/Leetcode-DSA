class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        s.insert(1);
        
        long ugly = 1;
        for(int i = 0 ; i < n ; i++) {
            ugly = *s.begin();
            s.erase(ugly);
            s.insert(ugly * 2);
            s.insert(ugly * 3);
            s.insert(ugly * 5);
        }
        
        return ugly;
    }
};