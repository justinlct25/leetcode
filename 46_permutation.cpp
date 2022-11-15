class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

    // Path: recorded in track (a track = a permutation)
    // Selection List: num element that are not exist in track
    // End Condition: all elements in nums appear in track
    void backtrack(vector<int>& nums, vector<int>& track) { 
        if (track.size() == nums.size()) {// end condition (reach the end node)
            res.push_back(track); 
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (std::find(track.begin(), track.end(), nums[i]) != track.end()) continue; // illegal selection not in selection list
            track.push_back(nums[i]); // select
            backtrack(nums, track); // enter the decision tree
            track.pop_back(); // deselection
        }
    }
};