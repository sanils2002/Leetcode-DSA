class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n - 1;
        
        int h = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(citations[mid] >= n - mid) {
                h = n - mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
    
        return h;
    }
};