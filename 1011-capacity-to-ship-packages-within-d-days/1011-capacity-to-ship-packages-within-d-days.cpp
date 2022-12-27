class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Initialize the left and right bounds of the binary search
        int left = 0, right = 0;
        for(int w : weights) {
            left = max(left, w);
            right += w;
        }

        //Perform binary search to find the minimum weight capacity
        while(left < right) {
            int mid = left + (right - left) / 2;
            int D = 1, weight = 0;

            //Check if all the packages can be shipped within "days" days with a weight capacity of "mid"
            for(int w : weights) {
                if(weight + w > mid) {
                    weight = 0;
                    D++;
                }
                weight += w;
            }

            //Update the bounds based on the result
            if (D > days) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }

        //Return the minimum weight capacity
        return left;
    }
};