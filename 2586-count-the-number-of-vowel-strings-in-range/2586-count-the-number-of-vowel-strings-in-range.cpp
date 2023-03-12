class Solution {
private:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++) {
            string word = words[i];
            if(is_vowel(word[0]) && is_vowel(word[word.size()-1])) {
                count++;
            }
        }
    
        return count;
    }
};