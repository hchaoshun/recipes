//dfs
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result, tmp, candidates, target, 0);
        return result;
    }
private:
    static void dfs(vector<vector<int>> &result, vector<int> &tmp, vector<int> &candidates,
                   int target, int index) {
        if (target == 0) {
            result.push_back(tmp);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] > target) return; //剪枝
            tmp.push_back(candidates[i]);
            dfs(result, tmp, candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};
