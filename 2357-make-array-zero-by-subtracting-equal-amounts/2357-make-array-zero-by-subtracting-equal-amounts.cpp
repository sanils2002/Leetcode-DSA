class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(auto &num: nums) {
            if(0 != num)
                s.insert(num);
        }
        
        return s.size();
    }
};