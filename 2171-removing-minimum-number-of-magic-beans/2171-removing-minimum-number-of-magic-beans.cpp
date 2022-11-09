class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long removed = 0, sz = beans.size();
        
        for(auto idx = 0 ; idx < sz ; idx++) {
            removed = max(removed, beans[idx] * (sz - idx));
        }
        return accumulate(beans.begin(), beans.end(), 0LL) - removed;
    }
};