class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        // Create a vector of pairs (quality, wage)
        vector<pair<double, int>> workers;
        for(int i = 0; i < n; i++) {
            workers.push_back({ static_cast<double>(wage[i]) / quality[i], quality[i] });
        }

        // Sort the workers based on the ratio of wage/quality
        sort(workers.begin(), workers.end(), less<pair<double, int>>());

        priority_queue<int> pq;
        int sum = 0;
        double minCost = numeric_limits<double>::max();

        for(const auto& worker : workers) {
            pq.push(worker.second);  // Push quality to the priority queue
            sum += worker.second;    // Keep track of the sum of quality

            if(pq.size() > k) {
                sum -= pq.top();  // Remove the worker with the maximum quality
                pq.pop();
            }

            if(pq.size() == k) {
                // Calculate the cost based on the current ratio and the sum of quality
                double cost = sum * worker.first;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};