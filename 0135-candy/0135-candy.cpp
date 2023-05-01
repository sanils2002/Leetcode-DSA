class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // initialize each child with 1 candy
        // first pass: from left to right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        // second pass: from right to left
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        // sum up the candies for all children
        return accumulate(candies.begin(), candies.end(), 0);
    }
};