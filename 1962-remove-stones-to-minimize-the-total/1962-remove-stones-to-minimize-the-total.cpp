class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Build min heap with '-' sign.
  std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
  for (int num : piles) {
    heap.push(-num);
  }

  // Iterate for k times and perform pile[i]//2.
  for (int i = 0; i < k; i++) {
    int curr = -heap.top();
    heap.pop();
    int remove = std::ceil(curr / 2.0);
    heap.push(-remove);
  }

  // Now return ans by putting them back into '+'.
  int total = 0;
  while (!heap.empty()) {
    total -= heap.top();
    heap.pop();
  }
  return total;
    }
};