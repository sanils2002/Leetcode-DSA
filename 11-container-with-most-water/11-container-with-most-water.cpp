class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int most_water = INT_MIN, bar = 0;
        
        while(left < right) {
            int node = right - left;
            bar = min(height[left], height[right]);
            most_water = max(most_water, node * bar);
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return most_water;
    }
};