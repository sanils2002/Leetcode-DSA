class SummaryRanges {
private:
    vector<vector<int>> intervals;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int n = intervals.size();
        vector<vector<int>> res;
        int l = value, r = value;
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] + 1 < l) {
                res.push_back(intervals[i]);
            } else if (r + 1 < intervals[i][0]) {
                res.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            } else {
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r});
        intervals = res;
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */