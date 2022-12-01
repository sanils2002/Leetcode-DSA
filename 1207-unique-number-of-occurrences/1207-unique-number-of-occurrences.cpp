class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        set<int> st;
        
        for(auto &a : arr) {
            mp[a]++;
        }
        
        for(auto &x : mp) {
            if(st.count(x.second))
                return false;
            else {
                st.insert(x.second);
            }
        }
        
        return true;
}
};