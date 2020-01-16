class Solution {
public:
    //todo 解决序列全为负数的问题
    int maxSubArray(vector<int>& nums) {
        int f = 0, result = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            f = max(f + nums[i], nums[i]);
            result = max(result, f);
        }
        return result;
    }
};
