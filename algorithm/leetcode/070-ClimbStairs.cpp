class Solution {
public:
    int climbStairs(int n) {
        int v = 0, w = 1;
        while (n--) {
            w = w + v;
            v = w - v;
        }
        return w;
    }
};
