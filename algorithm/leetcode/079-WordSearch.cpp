class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, visited, i, j, 0, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    static bool dfs(const vector<vector<char>>& board, const string word,
                    vector<vector<bool>> &visited, int i, int j, int index, int m, int n) {
        if (index == word.size()) return true; //收敛
        if (i >= m || j >= n || i < 0 || j < 0) return false; //越界终止
        if (visited[i][j]) return false; //剪枝
        if (board[i][j] != word[index]) return false; //剪枝
        
        visited[i][j] = true;
        bool ret = dfs(board, word, visited, i + 1, j, index+1, m, n) ||
                   dfs(board, word, visited, i, j + 1, index+1, m, n) ||
                   dfs(board, word, visited, i - 1, j, index+1, m, n) ||
                   dfs(board, word, visited, i, j - 1, index+1, m, n);
        visited[i][j] = false;
        return ret;
    }
};
