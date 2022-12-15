class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Create a hash map to store results of sub-problems.
        unordered_map<string, int> dp;
        
        // Define a recursive function to find the length of the LCS of substrings of text1 and text2.
        function<int(int, int)> findLCS = [&](int i, int j) {
            // If either string is empty, the LCS has length 0.
            if(i == 0 || j == 0) 
                return 0;
            
            // Create a key for the current sub-problem.
            string key = to_string(i) + "-" + to_string(j);

            // Check if the result for this sub-problem has already been computed.
            if(dp.find(key) != dp.end()) 
                return dp[key];

            // If the characters at the current positions in the two strings are the same,
            // the LCS has length one plus the LCS of the two strings without these characters.

            if(text1[i - 1] == text2[j - 1]) 
                return dp[key] = 1 + findLCS(i - 1, j - 1);

            // If the characters at the current positions in the two strings are different,
            // the LCS has length the maximum of the LCS of the two strings without these characters.
            return dp[key] = max(findLCS(i - 1, j), findLCS(i, j - 1));
        };
 
        // Call the recursive function to find the length of the LCS of the two input strings.
        return findLCS(m, n);
    }
};