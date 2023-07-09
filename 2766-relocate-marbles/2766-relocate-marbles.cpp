class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> ctr;

        // Count the occurrences of each marble in nums
        for(int num : nums) {
            ctr[num]++;
        }

        // Perform the marble moves
        for(int i = 0; i < moveFrom.size(); i++) {
            int strt = moveFrom[i];
            int dest = moveTo[i];

            int temp = ctr[strt];
            ctr[strt] = 0;
            ctr[dest] = temp;
        }

        // Extract the occupied positions from the updated counter
        vector<int> occupiedPositions;
        for(const auto& entry : ctr) {
            if(entry.second > 0) {
                occupiedPositions.push_back(entry.first);
            }
        }

        sort(occupiedPositions.begin(), occupiedPositions.end());
        return occupiedPositions;
    }
};