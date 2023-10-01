class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        string reversed;
        bool firstWord = true;
    
        while(iss >> word) {
            if(!firstWord) {
                reversed += " "; // Add a space between words
            }
            string reversedWord(word.rbegin(), word.rend());
            reversed += reversedWord;
            firstWord = false;
        }
    
        return reversed;
    }
};