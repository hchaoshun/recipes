class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int len = nums.size();
        if (len < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            //如果没有if会出现相同结果
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                    while (nums[k] == nums[k+1] && k > j) k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (nums[j] == nums[j-1] && j < k) j++;
                    while (nums[k] == nums[k+1] && k > j) k--;
                }
            }
        }
        return result;
    }
};
