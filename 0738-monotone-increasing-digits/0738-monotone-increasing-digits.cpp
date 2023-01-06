class Solution {
public:
    int monotoneIncreasingDigits(int n) {
       // Convert the number to a string for easier manipulation
  std::string str = std::to_string(n);

  // Iterate through the digits of the number, starting from the second-to-last digit
  for (int i = str.size() - 2; i >= 0; i--) {
    // If the current digit is greater than the next digit, decrement the current digit and set all the digits after it to 9
    if (str[i] > str[i + 1]) {
      str[i]--;
      for (int j = i + 1; j < str.size(); j++) {
        str[j] = '9';
      }
    }
  }

  // Convert the modified string back to an integer and return it
  return std::stoi(str);
    }
};