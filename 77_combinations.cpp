class Solution {
public:
    vector<vector<int>> combine(int n, int k) { // n defines the tree width, k defines the tree depth
        vector<vector<int>> res;
        if (n <= 0 || k <= 0) return res; // invalid case
        vector<int> comb;
        backtrack(n, k, 1, comb, res);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& comb, vector<vector<int>>& res) {
        if (k == comb.size()) {
            res.push_back(comb); // push new combination when its size reaches max size/tree depth(k)
            return;
        }
        for (int i = start; i <= n; i++) { // loop start from start idx avoids repeating combinations
            comb.push_back(i);
            backtrack(n, k, i+1, comb, res); // forming combination until it reaches max size/depth
            comb.pop_back();
        }
    }
};