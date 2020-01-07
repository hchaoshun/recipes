class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                tmp.push(c);
            } else {
                if (tmp.empty() || tmp.top() != left[right.find(c)]) {
                    return false;
                }
                tmp.pop();
            }
        }
        return tmp.empty();
    }
private:
    const string left = "([{";
    const string right = ")]}";
};
