class Solution {
private:
    void helper(int id, string &x) {
        if(id == x.size()) {
            v.push_back(s);
            return;
        }

        for(char &c: umap[x[id]]) {
            s.push_back(c);
            helper(id + 1, x);
            s.pop_back();
        }
    }
public:
    unordered_map<char, string> umap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> v;
    string s;
    
    vector<string> letterCombinations(string digits) {
        if(0 == digits.size())
            return v;
        helper(0, digits);
        return v;
    }
};