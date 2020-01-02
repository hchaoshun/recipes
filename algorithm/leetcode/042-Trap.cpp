class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n < 2) return 0;
        int *left = new int[n]();
        int *right = new int[n]();
        left[0] = height[0];
        right[n-1] = height[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
            right[n-1-i] = max(right[n-i], height[n-i-1]);
        }
        int result = 0;
        for (int i = 1; i < n; i++) {
            result += min(left[i], right[i]) - height[i];
        }
        delete []left;
        delete []right;
        return result;
    }
};
