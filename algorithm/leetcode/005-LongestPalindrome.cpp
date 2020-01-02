class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n == 0) return "";
        //dp存储从i到j是否是回文
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        int start = 0, len = 1;
        //从长度2开始更新dp
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && (l == 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    start = i;
                    len = l;
                }
            }
        }
        return s.substr(start, len);
    }
};
