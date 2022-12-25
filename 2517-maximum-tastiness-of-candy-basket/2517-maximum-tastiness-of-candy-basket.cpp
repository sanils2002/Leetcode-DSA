class Solution {
public:
    int maximumTastiness(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l=0,r=1e9;
        while(l<r) {
            int m=(l+r+1)>>1;
            int la=-1e9,pick=0;
            for(auto t:stalls) {
                if(t>=la+m) la=t,++pick;
            }
            if(pick>=k) l=m; else r=m-1;
        }
        return l;
    }
};