class Solution {
private:
    int bisectRight(vector<int>& arr, int value) {
        int left = 0, right = arr.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if(arr[mid] <= value) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }
        return left;
    }

    int dfs(int i, int prev, vector<int>& arr1, vector<int>& arr2, map<pair<int, int>, int>& dp) {
        if(i == arr1.size()) {
            return 0;
        }
    
        if(dp.count({i, prev})) {
            return dp[{i, prev}];
        }

        int cost = 2001;

        // If arr1[i] is already greater than prev, we can leave it be.
        if(arr1[i] > prev) {
            cost = dfs(i + 1, arr1[i], arr1, arr2, dp);
        }

        // Find a replacement with the smallest value in arr2.
        int idx = bisectRight(arr2, prev);

        // Replace arr1[i], with a cost of 1 operation.
        if(idx < arr2.size()) {
            cost = min(cost, 1 + dfs(i + 1, arr2[idx], arr1, arr2, dp));
        }

        dp[{i, prev}] = cost;
        return cost;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
    
        map<pair<int, int>, int> dp;
        int answer = dfs(0, -1, arr1, arr2, dp);
    
        return answer < 2001 ? answer : -1;
    }
};