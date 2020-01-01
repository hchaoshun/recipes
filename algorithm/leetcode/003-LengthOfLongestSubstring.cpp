class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int MAX_ASII = 256;
        int record[MAX_ASII];
        fill(record, record + MAX_ASII, -1);
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            //record[s[i]] != -1，start会倒退
            if (record[s[i]] >= start) {
                max_len = max(i - start, max_len);
                start = record[s[i]] + 1;
            }
            record[s[i]] = i;
        }
        return max((int)(s.size() - start), max_len);
    }
};
