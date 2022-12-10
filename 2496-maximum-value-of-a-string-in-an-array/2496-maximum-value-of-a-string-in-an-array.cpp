class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int max_value = 0;
        
        for(auto & s : strs) {
            bool is_digit = true;
            int n = s.size();
            for (char c : s) {
                if (!isdigit(c)) {
                    is_digit = false;
                    break;
                }
            }
            if (is_digit) {
                max_value = max(max_value, stoi(s));
            }
            else {
                max_value = max(max_value, n);
            }
        }
        
        return max_value;
    }
};