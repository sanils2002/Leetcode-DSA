class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) {
            return 0;
        }
    
        int count = 0;
        unordered_set<int> uniqueNums;
        unordered_set<int> visited;
    
        for(int num : nums) {
            if(uniqueNums.count(num - k) && !visited.count(num)) {
                count++;
                visited.insert(num);
            }
        
            if(uniqueNums.count(num + k) && !visited.count(num + k)) {
                count++;
                visited.insert(num + k);
            }
        
            uniqueNums.insert(num);
        }
    
        return count;
    }
};