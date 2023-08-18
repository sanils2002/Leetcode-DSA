class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); // Store the degree of each city
        unordered_map<int, unordered_set<int>> connectedCities; // Store the connected cities for each city
    
        for(const vector<int>& road : roads) {
            int city1 = road[0];
            int city2 = road[1];
        
            degree[city1]++;
            degree[city2]++;
        
            connectedCities[city1].insert(city2);
            connectedCities[city2].insert(city1);
        }
    
        int maxRank = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j];
            
                if(connectedCities[i].count(j)) { // If there is a direct road between the cities, subtract 1
                    rank--;
                }
            
                maxRank = max(maxRank, rank);
            }
        }
    
        return maxRank;
    }
};