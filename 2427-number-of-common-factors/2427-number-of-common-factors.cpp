class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        for(int idx = 1 ; idx <= a ; idx++) {
            if(0 == a%idx and 0 == b%idx)
                cnt++;
        }
        return cnt;
    }
};