class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        mergeSort(nums1, nums2, result);
        int len = result.size();
        if (len % 2) {
             return result[len/2];
        } else {
            return (result[len/2-1] + result[len/2]) * 1.0 / 2;
        }
    }
private:
    void mergeSort(vector<int> &nums1, vector<int> &nums2, vector<int> &result) {
        vector<int>::iterator p1 = nums1.begin();
        vector<int>::iterator p2 = nums2.begin();
        while (p1 != nums1.end() && p2 != nums2.end()) {
            if (*p1 < *p2) {
                result.push_back(*p1);
                p1++;
            } else {
                result.push_back(*p2);
                p2++;
            }
        }
        while (p1 != nums1.end()) {
            result.push_back(*p1);
            p1++;
        }
        while (p2 != nums2.end()) {
            result.push_back(*p2);
            p2++;
        }
    }
};
