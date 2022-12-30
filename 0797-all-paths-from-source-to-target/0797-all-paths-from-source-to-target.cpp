class Solution {
private:
    void findPaths(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths, int start = 0) {
        path.push_back(start);
        
        if (start == end) {
            paths.push_back(path);
            path.pop_back();
            return;// found a path from start to end
        } 
        
        for(int node : graph[start]) {
            findPaths(graph, path, paths, node);
        }

    path.pop_back();  // backtrack
}
public:
    int start, end;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        
        start = 0, end = graph.size()-1; 
        findPaths(graph, path, paths);
        
        return paths;
    }
};