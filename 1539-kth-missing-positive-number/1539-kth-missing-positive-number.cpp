class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int it = 0, cnt = 0;
        for(int i = 1 ; i <= arr.back() ; i++) {
            if(arr[it] == i)
                it++;
            else
                cnt++;
            if(k == cnt)
                return i;
        }
        
        return arr.back() + k - cnt;
    }
};