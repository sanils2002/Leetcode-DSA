class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(begin(nums), end(nums), 0.0), orig = sum, cnt = 0;
        priority_queue<double> pq(begin(nums), end(nums));
        while(sum * 2 > orig) {
            double n = pq.top(); pq.pop();
            sum -= n / 2; 
            pq.push(n / 2);    
            cnt++;
        }
    
        return cnt;
    }
};