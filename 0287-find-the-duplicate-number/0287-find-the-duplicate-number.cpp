class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
    
        // Phase 1: Find the intersection point of the two pointers.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
    
        // Phase 2: Find the entrance to the cycle.
        int ptr1 = nums[0];
        int ptr2 = slow;
        while(ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
    
        return ptr1;
    }
};