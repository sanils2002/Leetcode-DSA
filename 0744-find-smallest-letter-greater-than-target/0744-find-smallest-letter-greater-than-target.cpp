class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        char result = letters[0];  // Initialize result with the first character

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(letters[mid] <= target) {
                left = mid + 1;
            } 
            else {
                result = letters[mid];
                right = mid - 1;
            }
        }

        return result;
    }
};