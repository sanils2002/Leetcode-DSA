class DSU {
private:
     int count;
     vector<int> p;
public:
    DSU(int n) {
        count = n;
        p.resize(n);
        for(int i = 0; i < n; i++)
            p[i] = i;
    }
        
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void join(int x, int y) {
        p[find(x)] = find(y);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &e : edges)
            dsu.join(e[0], e[1]);
        unordered_map<int, int> m;
        unordered_map<int, int> sz;
        
        for(int i = 0; i < n; i++) {
            m[dsu.find(i)] = 0;
            sz[dsu.find(i)]++;
        }
        for(auto &e : edges) {
            int px = dsu.find(e[0]);
            int py = dsu.find(e[1]);
            if(px == py)
                m[px]++;
        }
        
        int ans = 0;
        for(auto &p : m) {
            if(sz[p.first] * (sz[p.first] - 1) / 2 == p.second)
                ans++;
        }
        
        return ans;
    }
};