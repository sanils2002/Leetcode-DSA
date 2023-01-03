class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numDeletions = 0;
        const int numColumns = strs[0].size();
        for(int j = 0 ; j < numColumns ; j++) {
            for(int i = 1 ; i < strs.size() ; i++) {
                if(strs[i][j] < strs[i - 1][j]) {
                    numDeletions++;
                    break;
                }
            }
        }
        
        return numDeletions;
    }
};