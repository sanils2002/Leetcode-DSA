class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), [](const int a, const int b) {
            return a > b;
        });
        
        int l = 0, ans = 0;
        for(int pt : processorTime) {
            int cx = 0, cnt = 0;
            while(l < tasks.size() and cnt < 4) {
                cx = max(cx, pt + tasks[l]);
                l++, cnt++;
            }
            ans = max(ans, cx);
        }
        
        return ans;
    }
};