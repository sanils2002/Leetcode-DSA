class Solution {
private:
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        if(graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }

        visited.insert(start);

        for(auto& neighbor : graph[start]) {
            const string& next = neighbor.first;
            if(visited.find(next) == visited.end()) {
                double result = dfs(next, end, visited);
                if(result != -1.0) {
                    return neighbor.second * result;
                }
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for(int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double value = values[i];

            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }

        // Perform DFS for each query
        vector<double> results;
        for(const auto& query : queries) {
            const string& C = query[0];
            const string& D = query[1];

            if(graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
            } 
            else {
                unordered_set<string> visited;
                double result = dfs(C, D, visited);
                results.push_back(result);
            }
        }

        return results;
    }
};