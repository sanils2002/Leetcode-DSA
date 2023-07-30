class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cx = 0;
        for(auto &h : hours)
            h >= target ? cx++ : cx += 0;
        return cx;
    }
};