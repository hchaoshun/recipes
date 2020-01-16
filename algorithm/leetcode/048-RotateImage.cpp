class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        //沿对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n - i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        //沿水平中线翻转
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
    }
};
