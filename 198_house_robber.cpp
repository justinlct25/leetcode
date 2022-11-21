class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0, temp = 0;
        for (int num : nums) {
            temp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};