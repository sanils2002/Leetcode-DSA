class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for(int i = 0; i < n; i++) {
            projects[i] = make_pair(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> pq; // max heap of profits
        int i = 0;
        while(k > 0) {
            // add projects to the heap that have enough capital
            while(i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }
            // pick the project with the highest profit
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
                k--;
            } 
            else {
                break; // no more projects available
            }
        }
    
        return w;
    }
};