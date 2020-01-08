class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const pair<vector<int>::iterator, vector<int>::iterator> p = 
            equal_range(nums.begin(), nums.end(), target);
        if (p.first == p.second || p.first == nums.end()) {
            return {-1, -1};
        } else {
            return {distance(nums.begin(), p.first), distance(nums.begin(), prev(p.second))};
        }
    }
};
