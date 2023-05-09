class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // Create a vector to store all possible word break solutions
        vector<vector<string>> solutions(n+1);

        // Set the base case where there is only one solution for an empty string
        solutions[0] = {""};

        // Use dynamic programming to find all possible solutions for s
        for(int i = 1; i <= n; i++) {
            vector<string> cur;
            for(int j = 0; j < i; j++) {
                if(!solutions[j].empty() && dict.count(s.substr(j, i-j))) {
                    // If the substring from j to i is in the dictionary,
                    // add it to the current solution
                    for(string prev : solutions[j]) {
                        cur.push_back(prev + (prev.empty() ? "" : " ") + s.substr(j, i-j));
                    }
                }
            }
            solutions[i] = cur;
        }

        // Return the solutions for the entire string
        return solutions[n];
    }
};