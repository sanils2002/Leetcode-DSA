class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert the numbers to strings
        vector<string> nums_str;
        for(int num : nums) {
            nums_str.push_back(to_string(num));
        }

        // Sort the numbers using the custom comparison function
        sort(nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // If the largest number is "0", return "0" (to handle cases like [0, 0])
        if(nums_str[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings to form the largest number
        string result;
        for(string num_str : nums_str) {
            result += num_str;
        }

        return result;
    }
};