class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> secretCount;
        unordered_map<char, int> guessCount;

        // Count bulls and populate maps
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } 
            else {
                secretCount[secret[i]]++;
                guessCount[guess[i]]++;
            }
        }

        // Count cows
        for(auto& entry : guessCount) {
            char digit = entry.first;
            int count = entry.second;
            if(secretCount.count(digit)) {
                cows += min(secretCount[digit], count);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};