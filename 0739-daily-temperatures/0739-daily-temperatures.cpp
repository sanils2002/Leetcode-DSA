class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<int> s;
        
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            answer[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        
        return answer;
    }
};