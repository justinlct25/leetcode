class Solution {
public:

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(res, s, 0);
        return res;
    }

    void backtrack(vector<string>& res, string s, int idx) {
        if (idx == s.size()) {
            res.push_back(s);
            return;
        }
        if (!isalpha(s[idx])) {
            backtrack(res, s, idx+1);
            return;
        }
        s[idx] = tolower(s[idx]);
        backtrack(res, s, idx+1);
        s[idx] = toupper(s[idx]);
        backtrack(res, s, idx+1);
    }
};