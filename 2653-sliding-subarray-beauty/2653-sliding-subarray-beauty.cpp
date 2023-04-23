#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
class Solution {
private:
    void myerase(ordered_set &t, int v){
        int rank = t.order_of_key(v);
        ordered_set::iterator it = t.find_by_order(rank);
        t.erase(it);
    }
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        ordered_set st;
        int i = 0, j = 0;
        vector<int> ans;
        
        while(j < nums.size()) {
            if(nums[j] < 0)
                st.insert(nums[j]);
            if(j - i + 1 == k) {
                if(st.size() < x)
                    ans.push_back(0);
                else {
                    auto temp = st.find_by_order(x-1);
                    ans.push_back(*temp);
                }
                if(nums[i] < 0)
                    myerase(st,nums[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};