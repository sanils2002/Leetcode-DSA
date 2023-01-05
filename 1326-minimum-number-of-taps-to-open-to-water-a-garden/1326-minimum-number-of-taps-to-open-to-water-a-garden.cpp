class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int taps = 0;
        int mx = INT_MIN, mn = 0;
        int idx = 0; //Tap-0
        
        while(mx < n) {
            for(int i = idx ; i < ranges.size() ; i++) {
                if(i - ranges[i] <= mn and i + ranges[i] > mx) {
                    idx = i;
                    mx = i + ranges[i];
                }
            }
            
            if(mx == mn)
                return -1; //No area covered
            taps++;
            mn = mx;
        }
        
        return taps;
    }
};