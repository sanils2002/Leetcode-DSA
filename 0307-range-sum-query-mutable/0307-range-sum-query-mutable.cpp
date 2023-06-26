class NumArray {
private:
    vector<int> b;
    int len;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        double l = sqrt(nums.size());
        len = ceil(nums.size() / l);
        b.resize(len, 0);
        for (int i = 0; i < nums.size(); i++)
            b[i / len] += nums[i];
    }
    
    void update(int index, int val) {
        int b_l = index / len;
        b[b_l] = b[b_l] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / len;
        int endBlock = right / len;
        if (startBlock == endBlock) {
            for (int k = left; k <= right; k++)
                sum += nums[k];
        } else {
            for (int k = left; k <= (startBlock + 1) * len - 1; k++)
                sum += nums[k];
            for (int k = startBlock + 1; k <= endBlock - 1; k++)
                sum += b[k];
            for (int k = endBlock * len; k <= right; k++)
                sum += nums[k];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */