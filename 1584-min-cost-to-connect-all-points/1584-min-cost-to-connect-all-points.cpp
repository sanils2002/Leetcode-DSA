class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
    
        // Create a list of edges with their Manhattan distances
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
    
        // Sort the edges by distance in ascending order
        sort(edges.begin(), edges.end());
    
        UnionFind uf(n);
        int minCost = 0;
    
        // Kruskal's algorithm to find the minimum spanning tree
        for(auto& edge : edges) {
            int dist = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
        
            if(uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                minCost += dist;
            }
        }
    
        return minCost;
    }
};