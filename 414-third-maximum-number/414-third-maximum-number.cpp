class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto & num : nums)
            s.insert(num);
        int n = s.size();
        vector<int> v(s.begin(),s.end()); 
        if(n < 3)
            return v[n-1];
        return v[n-3];
    }
};