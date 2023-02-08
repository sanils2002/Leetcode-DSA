class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(int p : piles) 
            r = max(r, p);
        
        while(l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for(int p : piles) 
                cnt += ceil(p / (double)m);
            if(cnt > h) 
                l = m + 1;
            else 
                r = m;
        }
        
        return l;
    }
};