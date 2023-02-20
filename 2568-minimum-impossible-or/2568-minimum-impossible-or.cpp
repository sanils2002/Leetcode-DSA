class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1 ; ; i *= 2)
            if(count(nums.begin(), nums.end(), i) == 0)
                return i;
    }
};