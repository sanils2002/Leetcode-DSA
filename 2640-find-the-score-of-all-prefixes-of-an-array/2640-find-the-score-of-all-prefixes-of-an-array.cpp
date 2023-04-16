class Solution {
private:
    vector<long long> getConversionArray(vector<int>& arr) {
        int n = arr.size();
        vector<long long> conver(n);
        int maxVal = arr[0];
        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal, arr[i]);
            conver[i] = arr[i] + maxVal;
        }
        
        return conver;
}
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixScores(n);
        vector<long long> conver = getConversionArray(nums);
        for(int i = 0; i < n; i++) {
            prefixScores[i] = (i == 0 ? conver[i] : conver[i] + prefixScores[i-1]);
        }
        
        return prefixScores;
    }
};