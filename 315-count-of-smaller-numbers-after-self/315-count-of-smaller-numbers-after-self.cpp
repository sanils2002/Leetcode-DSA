#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set<int> tr_cont;
        vector<int> counts;
        int n = nums.size();
        
        for(int idx = n - 1 ; idx >= 0 ; --idx) {
            counts.push_back(tr_cont.order_of_key(nums[idx]));
            tr_cont.insert(nums[idx]);
        }
        
        reverse(counts.begin(), counts.end());
        return counts;
    }
};