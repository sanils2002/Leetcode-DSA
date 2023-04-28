class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        count = n;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) {
            return;
        }
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } 
        else if(rank[px] > rank[py]) {
            parent[py] = px;
        } 
        else {
            parent[py] = px;
            rank[px]++;
        }
        count--;
    }
};

class Solution {
private:
    bool isSimilar(string& s1, string& s2) {
        int n = s1.size();
        int diff = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diff++;
                if(diff > 2) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.count;
    }
};