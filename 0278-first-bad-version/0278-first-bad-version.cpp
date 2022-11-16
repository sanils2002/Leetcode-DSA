// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1, en = n;
        while(st <= en) {
            int mid = st + (en - st)/2;
            if(false == isBadVersion(mid)) 
               st = mid + 1;
            else 
               en = mid - 1;
        }
        return st;
    }
};