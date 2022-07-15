class Solution {
protected:
    #define f1(idx, a, n) for(int idx = a ; idx < n ; idx++)
    #define sz size
public:
    int minMoves(vector<int>& nums) {
        int moves = 0, min__eq = nums[0];
        int n = nums.sz();
        f1(idx, 0, n) {
            moves += nums[idx];
            min__eq = min(nums[idx], min__eq);
        }
        moves -= n*min__eq;
        return moves;
    }
};