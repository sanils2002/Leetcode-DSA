class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights); // Copy heights into expected
        sort(expected.begin(), expected.end()); // Sort expected in non-decreasing order
    
        int count = 0;
        for(int i = 0; i < heights.size(); ++i) {
            if(heights[i] != expected[i]) {
                count++;
            }
        }
    
        return count;
    }
};