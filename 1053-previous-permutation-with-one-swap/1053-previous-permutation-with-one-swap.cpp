class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;
        while(i >= 0 && arr[i] <= arr[i + 1]) 
            i--;
        if(i < 0) 
            return arr;
        
        int j = i + 1;
        while(j < n && arr[j] < arr[i]) 
            j++;
        j--;

        while(j > i + 1 && arr[j - 1] == arr[j]) 
            j--;

        swap(arr[i], arr[j]);
        return arr;
    }
};