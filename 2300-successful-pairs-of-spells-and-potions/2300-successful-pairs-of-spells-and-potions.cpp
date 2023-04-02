class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
    vector<int> pairs(n, 0);
    
    sort(potions.begin(), potions.end()); // Sort the potions array
    
    for (int i = 0; i < n; i++) {
        // Perform binary search to find the first index j where spells[i] * potions[j] >= success
        int lo = 0;
        int hi = m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if ((long long)spells[i] * potions[mid] >= success) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        pairs[i] = m - lo; // Update the number of successful pairs for the ith spell
    }
    
    return pairs;
    }
};