class Solution {
private:
    string mergeStrings(const string& a, const string& b) {
        if(a.find(b) != string::npos) {
            return a;
        }
        for(int i = min(a.length(), b.length()); i >= 0; i--) {
            if(a.substr(a.length() - i) == b.substr(0, i)) {
                return a + b.substr(i);
            }
        }
        return a + b;
    }
public:
    string minimumString(string a, string b, string c) {
        vector<string> arr = {a, b, c};
        int n = arr.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i != j && j != k && i != k) {
                        string s1 = mergeStrings(arr[i], arr[j]);
                        string s2 = mergeStrings(s1, arr[k]);
                        if(ans == "" || (s2.length() < ans.length()) || (s2.length() == ans.length() && s2 < ans)) {
                            ans = s2;
                        }
                    }
                }
            }
        }
        return ans;
    }
};