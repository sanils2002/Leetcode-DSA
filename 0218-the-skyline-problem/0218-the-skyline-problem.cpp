class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>> max_heap; // max-heap to keep track of maximum height
        int i = 0, n = buildings.size(), x, y, prev = 0;
        
        while(i < n || !max_heap.empty()) {
            if(max_heap.empty() || (i < n && buildings[i][0] <= max_heap.top().second)) {
                // new building encountered, add its left endpoint to priority queue
                x = buildings[i][0];
                while(i < n && buildings[i][0] == x) {
                    max_heap.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            } 
            else {
                // an old building's right endpoint encountered, remove it from priority queue
                x = max_heap.top().second;
                while(!max_heap.empty() && max_heap.top().second <= x) {
                    max_heap.pop();
                }
            }
            y = max_heap.empty() ? 0 : max_heap.top().first;
            if(y != prev) {
                // current maximum height has changed, add a new key point
                result.push_back(vector<int>{x, y});
                prev = y;
            }
        }
        
        return result;
    }
};