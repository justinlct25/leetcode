class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size()+1, 0);
        for (int j = triangle.size()-1; j >= 0; j--) {
            for (int i = 0; i < triangle[j].size(); i++) {
                dp[i] = triangle[j][i] + min(dp[i], dp[i+1]);
            }
        }
        return dp[0];
    }
};