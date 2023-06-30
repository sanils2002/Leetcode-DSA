class DSU {
    vector<int> root, size;

public:
    DSU(int n) {
        root.resize(n);
        for(int i = 0; i < n; i++) {
            root[i] = i;
        }
        size.resize(n, 1);
    }

    int find(int x) {
        if(root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }

        if (size[rootX] > size[rootY]) {
            swap(rootX, rootY);
        }
        root[rootX] = rootY;
        size[rootY] += size[rootX];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row * col + 2);
        vector<vector<int>> grid(row, std::vector<int>(col, 0));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
            int index1 = r * col + c + 1;
            for (const auto& d : directions) {
                int newR = r + d[0], newC = c + d[1];
                int index2 = newR * col + newC + 1;
                if (newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1) {
                    dsu.unionSets(index1, index2);
                }
            }
            if (r == 0) {
                dsu.unionSets(0, index1);
            }
            if (r == row - 1) {
                dsu.unionSets(row * col + 1, index1);
            }
            if (dsu.find(0) == dsu.find(row * col + 1)) {
                return i;
            }
        }
        return -1;
    }
};