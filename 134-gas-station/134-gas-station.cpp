class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, rem = 0, curr = 0;
        for(int idx = 0 ; idx < gas.size() ; idx++) {
            curr += (gas[idx] - cost[idx]);
            if(curr < 0) {
                start = idx + 1;
                rem += curr;
                curr = 0;
            }
        }
        return (rem+curr) >= 0 ? start:-1;
    }
};