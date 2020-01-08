class Solution {
public:
    //折半后一定有一边有序
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first != last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) return mid;
            if (nums[first] <= nums[mid]) {//[first, mid)一定有序
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {//[mid, last)一定有序
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};
