class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, bool> m;
        int sanil;
        
        for(auto x : nums) {
            m[x] = false;
        }
        
        for(auto x : nums) {
            if(!m[x]) {
                m[x] = true;
            }
            else {
                sanil = x;
            }
        }
        
        return sanil;
    }
};