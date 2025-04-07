//最好情况，每次划分都平均，pivot总是在中央,T(n) = 2*T(n/2) + n => T(n) = nlog(n);
//最坏情况，初始序列已经有序，第1趟排序经过n-1次比较后，将第1个元素仍然定在原来的位置上，并得到一个长度为n-1的子序列；
//第2趟排序经过n-2次比较后，将第2个元素确定在它原来的位置上，又得到一个长度为n-2的子序列；以此类推，最终总的比较次数：
//C(n) = (n-1) + (n-2) + ... + 1 = n(n-1)/2
//最坏的情况下，快速排序的时间复杂度为O(n^2)
class Solution {
public:
    template <typename T>
    void quickSort(vector<T> &vec, int lo, int hi) {
        if (hi - lo < 2) return;
        int mid = partition(vec, lo, hi-1);
        quickSort(vec, lo, mid);
        quickSort(vec, mid+1, hi);
    }

    template <typename T>
    int partition(vector<T> &vec, int lo, int hi) {
        //避免最坏情况发生
        swap(vec[lo], vec[lo + rand()%(hi - lo + 1)]);
        T pivot = vec[lo];
        while (lo < hi) {
            while (lo < hi && pivot <= vec[hi]) hi--;
            vec[lo] = vec[hi];
            while (lo < hi && vec[lo] <= pivot) lo++;
            vec[hi] = vec[lo];
        }
        vec[lo] = pivot;
        return lo;
    }
};
