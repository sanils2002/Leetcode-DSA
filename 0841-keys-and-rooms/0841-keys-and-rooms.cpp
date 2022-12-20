class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Set to keep track of which rooms have been visited
        unordered_set<int> visited;
        
        // Queue to store keys that have not been used yet
        vector<int> keys;
        // Add keys from room 0 to the queue
        keys.insert(keys.end(), rooms[0].begin(), rooms[0].end());
        // Mark room 0 as visited
        visited.insert(0);

        while(!keys.empty()) {
            // Get the first key in the queue
            int key = keys.front();
            keys.erase(keys.begin());
        
            // If the room corresponding to this key has not been visited yet
            if(!visited.count(key)) {
                // Mark the room as visited
                visited.insert(key);
                // Add the keys from this room to the queue
                keys.insert(keys.end(), rooms[key].begin(), rooms[key].end());
            }
        }

        // Return true if all rooms have been visited, false otherwise
        return visited.size() == rooms.size();
    }
};