class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> oddn, evenn, oddt, event;
        
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(nums[idx] % 2)
                oddn.push_back(nums[idx]);
            else
                evenn.push_back(nums[idx]);
        }
        
        for(int idx = 0 ; idx < target.size() ; idx++) {
            if(target[idx] % 2)
                oddt.push_back(target[idx]);
            else
                event.push_back(target[idx]);
        }
        
        long long cost = 0;
        
        for(int idx = 0 ; idx < oddn.size() ; idx++) {
            if(oddn[idx] < oddt[idx])
                cost += (oddt[idx] - oddn[idx]) / 2;
        }
        for(int idx = 0 ; idx < evenn.size() ; idx++) {
            if(evenn[idx] < event[idx])
                cost += (event[idx] - evenn[idx]) / 2;
        }
        
        return cost;
    }
};