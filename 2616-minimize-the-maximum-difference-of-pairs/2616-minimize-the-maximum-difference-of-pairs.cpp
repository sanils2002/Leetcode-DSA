class Solution {
private:
    bool pass(vector<int> &nums, int x, int p) {
        int cnt = 0, n = nums.size();
        for(int i = 0 ; i < n - 1 ; i++) {
            if(nums[i + 1] - nums[i] <= x) 
                cnt++, i++;
        }
        
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int st = 0, en = 1e9, ans;
        while(st <= en) {
            int mid = st + ((en - st) / 2);
            if(pass(nums, mid, p)) 
                en = mid - 1, ans = mid;
            else 
                st = mid + 1;
        }
        return ans;
    }
};