class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> frequency;
  for (int task : tasks) {
    frequency[task]++;
  }

  int res = 0;
  for (const auto& [task, freq] : frequency) {
    if (freq == 1) {
      return -1;
    }
    res += ceil(freq / 3.0);
  }
  return res;
    }
};