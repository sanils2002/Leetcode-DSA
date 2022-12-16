class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Add a sentinel value at the end of the vector to handle the case where
        // the last element is the highest.
        heights.push_back(0);

        std::stack<int> stack;
        int max_area = 0;
        for(int i = 0; i < heights.size(); ++i) {
            // Keep removing elements from the stack until we find an element
            // that is smaller than the current one or the stack is empty.
            
            while(!stack.empty() && heights[stack.top()] > heights[i]) {
                int height = heights[stack.top()];
                stack.pop();
                
                // Calculate the area for the rectangle formed by the popped element.
                // The width of the rectangle is the distance between the current
                // position and the start of the rectangle.
                
                int width = stack.empty() ? i : i - stack.top() - 1;
                max_area = std::max(max_area, width * height);
            }
            // Push the current element onto the stack.
            stack.push(i);
        }
        
        return max_area;
    }
};