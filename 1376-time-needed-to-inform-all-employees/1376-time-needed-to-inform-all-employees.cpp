class Solution {
private:
    int dfs(int employee, vector<vector<int>>& adjList, unordered_map<int, int>& informTime) {
        int maxTime = 0;
        for(int subEmployee : adjList[employee]) {
            maxTime = max(maxTime, dfs(subEmployee, adjList, informTime));
        }
    
        return maxTime + informTime[employee];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        unordered_map<int, int> informTimeMap;
        for(int i = 0; i < n; i++) {
            informTimeMap[i] = informTime[i];
        }

        return dfs(headID, adjList, informTimeMap);
    }
};