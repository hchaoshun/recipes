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
        swap(vec[lo], vec[lo + rand()%(hi - lo) - 1]);
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
}
