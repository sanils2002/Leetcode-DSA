class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1+n2 != n3) return false;
        bool ans[n1+1][n2+2];
        for (int idx = 0 ; idx <= n1; idx++){
            for (int jdx = 0 ; jdx <= n2; jdx++){
                if (0 == idx && 0 == jdx) 
                    ans[idx][jdx] = true;
                else if (0 == idx) 
                    ans[idx][jdx] = ans[idx][jdx - 1] && (s2[jdx - 1] == s3[idx + jdx - 1]);
                else if (0 == jdx) 
                    ans[idx][jdx] = ans[idx - 1][jdx] && (s1[idx - 1] == s3[idx + jdx - 1]);
                else 
                    ans[idx][jdx] = (ans[idx][jdx - 1] && (s2[jdx - 1] == s3[idx + jdx - 1])) || (ans[idx - 1][jdx] && (s1[idx - 1] == s3[idx + jdx - 1]));
            }
        }
        return ans[n1][n2];
    }
};