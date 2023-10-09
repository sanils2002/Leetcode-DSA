class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!s.empty() && s.top() <= nums[i])
                s.pop();
            
            ans[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(ans[i] == -1){
                while(!s.empty() && s.top() <= nums[i])
                    s.pop();

                ans[i] = s.empty() ? -1 : s.top();
            }
            s.push(nums[i]);
        }
    
        return ans;
    }
};