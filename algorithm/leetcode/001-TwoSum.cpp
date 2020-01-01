class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            um[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int gap = target - nums[i];
            if (um.find(gap) != um.end() && i != um[gap]) {
                result.push_back(i);
                result.push_back(um[gap]);
                break;
            }
        }
        return result;
    }
};
