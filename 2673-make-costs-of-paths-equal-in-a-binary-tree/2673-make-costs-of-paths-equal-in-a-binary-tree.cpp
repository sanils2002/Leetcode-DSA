class Solution {
private:
    void update(int p, int v, int n, vector<int>& cost, vector<int>& st) {
        if(p >= n) {
            return;
        }
        
        st[p] = v + cost[p];
        update(2 * p + 1, st[p], n, cost, st);
        update(2 * p + 2, st[p], n, cost, st);
    }
    
    int helper(int l, int r, int n, vector<int>& st, int max_value) {
        if(l > r) {
            return 0;
        }
        
        int current_max = *max_element(st.begin() + l, st.begin() + r + 1);
        int ans = max_value - current_max;

        
        for(int i = l; i <= r; i++) {
            st[i] += max_value - current_max;
        }

        if(l != r) {
            int m = (l + r) / 2;
            ans += helper(l, m, n, st, max_value);
            ans += helper(m + 1, r, n, st, max_value);
        }

        return ans;
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> st(n, 0);
        update(0, 0, n, cost, st);
        int max_value = *max_element(st.begin() + n / 2, st.end());
        int ans = helper(n / 2, n - 1, n, st, max_value);
        return ans;
    }
};