class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int> v;
        for(auto &num : nums) {
            if(0 == num%3 and 0 == num%2)
                v.push_back(num);
        }
        
        int sum = 0;
        for(auto &x : v) {
            sum += x;
        }
        
        if(v.size())
            return sum / v.size();
        return 0;
    }
};