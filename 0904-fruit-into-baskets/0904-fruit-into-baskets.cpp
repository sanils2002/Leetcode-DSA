class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int max_fruits = 0;
        unordered_map<int, int> fruit_count;
        int left = 0, right = 0;
        while(right < fruits.size()) {
            fruit_count[fruits[right]]++;
            while(fruit_count.size() > 2) {
                fruit_count[fruits[left]]--;
                if(fruit_count[fruits[left]] == 0) {
                    fruit_count.erase(fruits[left]);
                }
                left++;
            }
            max_fruits = max(max_fruits, right - left + 1);
            right++;
        }
    
        return max_fruits;
    }
};