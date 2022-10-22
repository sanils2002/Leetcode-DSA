class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        //votrubac approach
        int totalDresses = 0, n = machines.size();
        for(auto idx = 0 ; idx < n ; idx++)
            totalDresses += machines[idx];
        if(0 != totalDresses % n)
            return -1;
        
        auto targetDresses = totalDresses / n, totalMoves = 0, balance = 0;
        for(auto idx = 0 ; idx < n ; idx++) {
            balance += machines[idx] - targetDresses;
            totalMoves = max(totalMoves, max(machines[idx] - targetDresses, abs(balance)));
        }
        
        return totalMoves;
    }
};