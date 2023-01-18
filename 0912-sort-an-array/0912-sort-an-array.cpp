class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       priority_queue<int, vector<int>, greater<int>> pq; //Min Heap
        for(auto &num : nums)
            pq.push(num);
        
        vector<int> v;
        while(!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }
        
        return v;
    }
};