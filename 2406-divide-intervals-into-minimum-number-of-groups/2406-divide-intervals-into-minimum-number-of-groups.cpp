class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int val = 1;

        for(int idx = 0 ; idx < intervals.size() ; idx++) {
            int st = intervals[idx][0], en = intervals[idx][1];

            if(!pq.empty() && pq.top() > st)
                val++;
            else if(!pq.empty()) 
                pq.pop();

            pq.push(en + 1);
        }

        return val;
    }
};