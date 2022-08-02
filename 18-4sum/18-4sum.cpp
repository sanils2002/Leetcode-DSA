class Solution {
private:
    typedef long long ll;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> fin_val;
        set<vector<int>> s;
        
        for(int idx = 0 ; idx < nums.size() - 1 ; idx++) {
            for(int jdx = idx + 1 ; jdx < nums.size() - 2 ; jdx++) {
                vector<int> feed_back;
                feed_back.push_back(nums[idx]);
                feed_back.push_back(nums[jdx]);
                int low = jdx + 1, high = nums.size() - 1;
                while(low < high) {
                    long long four_sum = ll(nums[idx]) + ll(nums[jdx]) + ll(nums[low]) + ll(nums[high]);
                    if(target == four_sum) {
                        feed_back.push_back(nums[low]);
                        feed_back.push_back(nums[high]);
                        fin_val.push_back(feed_back);
                        s.insert(feed_back);
                        
                        feed_back.pop_back();
                        feed_back.pop_back();
                        low++;
                    }
                    else if(four_sum > target) {
                        high--;
                    }
                    else {
                        low++;
                    }
                }
            }
        }
        
        vector<vector<int>> array;
        for(auto &ip : s) {
            array.push_back(ip);
        }
        
        return array;
    }
};