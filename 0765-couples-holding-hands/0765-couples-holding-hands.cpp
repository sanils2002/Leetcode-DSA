class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2; // Number of couples
        unordered_map<int, int> index; // Maps person ID to index
        
        for(int i = 0; i < row.size(); ++i) {
            index[row[i]] = i;
        }
        
        int swaps = 0;
        for(int i = 0; i < n; ++i) {
            int person1 = row[2 * i];
            int person2 = row[2 * i + 1];
            
            int couplePartner = person1 ^ 1; // XOR with 1 to find partner's ID
            
            if(row[2 * i + 1] != couplePartner) {
                int partnerIndex = index[couplePartner];
                swap(row[2 * i + 1], row[partnerIndex]);
                swap(index[person2], index[couplePartner]);
                swaps++;
            }
        }
        
        return swaps;
    }
};