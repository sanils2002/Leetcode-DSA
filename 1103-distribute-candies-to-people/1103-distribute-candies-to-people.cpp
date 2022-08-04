class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> fin_val(num_people, 0);
        int count = 0;
        
        while(candies) {
            fin_val[count%num_people] += min(count + 1, candies);
            candies -= min(count + 1, candies);
            count++;
        }
        
        return fin_val;
    }
};