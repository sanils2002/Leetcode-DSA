class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int sum = 0;
        int min_ele = *min_element(salary.begin(), salary.end());
        int max_ele = *max_element(salary.begin(), salary.end());
        
        for(auto &s : salary) {
            sum += s;
        }
        
        return (double)(sum - min_ele - max_ele) / (salary.size() - 2);
    }
};