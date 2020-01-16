//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[1][1]= 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (i == 1 || j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        return dp[m][n];
    }
};

//dfs
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 1 || n <= 1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};
