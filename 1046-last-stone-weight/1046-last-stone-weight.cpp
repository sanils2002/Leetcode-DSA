class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a max-heap of stones
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // Smash the heaviest two stones until there's one or none left
        while(maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if(x != y) {
                maxHeap.push(y - x);
            }
        }
        
        // Return the weight of the last stone or 0 if there are none
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};