class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> result(intervals.size());
        vector<pair<int, int>> starts;
        for(int i = 0; i < intervals.size(); i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        for(int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(end, 0));
            if(it == starts.end()) {
                result[i] = -1;
            } 
            else {
                result[i] = it->second;
            }
        }
    
        return result;
    }
};