class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> operations(length + 1, vector<int>(4,0));
        for(int i = 0; i < length ; i++){ 
            for(int count = 1 ; count < 4 ; count++){
                if(count == nums[i]) {
                     operations[i+1][count]=  1 + operations[i][count];
                }
                else {
                    operations[i+1][count] = operations[i][count];
                }
            }
        }

        int minOps = length;
        for(int i = 0; i <= length ; i++) { 
            for(int j = i ; j <= length ; j++){
                for(int k = j ; k <= length ; k++){ 
                    int onesCount = operations[i][1];
                    int twosCount = operations[j][2]-operations[i][2];
                    int threesCount = operations[k][3]-operations[j][3];
                    minOps = min(minOps, length - onesCount - twosCount- threesCount);
                }
            }
        }

        return minOps;
    }
};