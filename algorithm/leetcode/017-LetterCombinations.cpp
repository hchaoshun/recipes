//dfs问题
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        dfs(digits, 0, "", result);
        return result;
    }
private:
    void dfs(string digits, int cur, string tmp, vector<string> &result) {
        if (cur == digits.size()) {
            result.push_back(tmp);
            return;
        }
        for (auto &c : record[digits[cur] - '0']) {
            dfs(digits, cur + 1, tmp + c, result);
        }
    }
private:
    const vector<string> record = {"", "", "abc", "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
