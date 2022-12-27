class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        int count = 0;
        
        vector<int> DIFF(n);
        
        for(int i = 0 ; i < n ; i++) 
            DIFF[i] = capacity[i] - rocks[i];
        
        sort(DIFF.begin(), DIFF.end());
        for(int i = 0 ; i < n ; i++) {
            if(additionalRocks >= DIFF[i]) {
                additionalRocks -= DIFF[i];
                count++;
            }
            else
                break;
        }
        
        return count;
    }
};