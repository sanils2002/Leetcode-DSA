class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj; // Using multiset for lexical order
        vector<string> itinerary;
    
        // Build the adjacency list
        for(const auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
    
        // Helper function for DFS
        function<void(string)> dfs = [&](string airport) {
            while(!adj[airport].empty()) {
                string next = *adj[airport].begin();
                adj[airport].erase(adj[airport].begin());
                dfs(next);
            }
            itinerary.push_back(airport);
        };
    
        // Start DFS from JFK
        dfs("JFK");
    
        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
    
        return itinerary;
    }
};