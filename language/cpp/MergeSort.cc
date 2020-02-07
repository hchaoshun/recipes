template <typename T>
void mergeSort(T *arr, int lo, int hi) {
    if (hi - lo < 2) return;
    int mid = (lo + hi) >> 1;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid, hi);
    merge(arr, lo, mid, hi);
}

template <typename T>
void merge(T *arr, int lo, int mid, int hi) {
    T *A = arr + lo;
    int lb = mid - lo;
    T *B= new T[lb];
    for (int i = 0; i < lb;) B[i] = A[i++];

    int lc = hi - mid;
    T *C = arr + mid;
    for (int i = 0, j = 0, k = 0; j < lb || k < lc;) {
        if (j < lb && (k >= lc || B[j] <= C[k])) A[i++] = B[j++];
        if (k < lc && (j >= lb || C[k] < B[j])) A[i++] = C[k++];
    }

    delete []B;
}
