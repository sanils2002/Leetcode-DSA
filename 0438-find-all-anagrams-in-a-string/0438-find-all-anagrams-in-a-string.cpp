class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Create a map to store the frequencies of characters in p
        unordered_map<char, int> p_freq;
        for (char c : p) {
            p_freq[c]++;
        }

        // Create a vector to store the start indices of anagrams
        vector<int> anagram_indices;

        // Create a map to store the frequencies of characters in the current window
        unordered_map<char, int> window_freq;

        // Initialize the size of the window and the number of matching characters
        int window_size = p.size();
        int num_matching_chars = 0;

        // Slide the window over the string s
        for(int i = 0; i < s.size(); i++) {
            // Add the current character to the window
            char c = s[i];
            window_freq[c]++;

            // Check if the current character is in p
            if(p_freq.count(c) && window_freq[c] <= p_freq[c]) {
                num_matching_chars++;
            }

            // If the window size is greater than the length of p, remove the character at the left side of the window
            if(i >= window_size) {
                c = s[i - window_size];
                window_freq[c]--;
                if(p_freq.count(c) && window_freq[c] < p_freq[c]) {
                    num_matching_chars--;
                }
            }

            // If the current window is an anagram, add its start index to the result
            if(num_matching_chars == window_size) {
                anagram_indices.push_back(i - window_size + 1);
            }
        }

        return anagram_indices;
    }
};