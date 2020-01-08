class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while(permutation(nums.begin(), nums.end()));
        return result;
    }
    
private:
    template <typename Ite>
    static bool permutation(Ite begin, Ite end) {
        const auto rfirst = reverse_iterator<Ite>(end);
        const auto rlast = reverse_iterator<Ite>(begin);
        
        auto pivot = next(rfirst);
        while (pivot != rlast && *pivot >= *prev(pivot)) ++pivot;
        
        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return false;
        }
        const auto change = find_if(rfirst, pivot, [pivot](const int n) {
            return n > *pivot;
        });
        swap(*pivot, *change);
        reverse(rfirst, pivot);
        return true;
    }
};
