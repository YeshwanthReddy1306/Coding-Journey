class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int start, vector<int>& nums, vector<int>& curr) {
        res.push_back(curr);

        for(int i = start; i < nums.size(); i++) {

            // Skip duplicates
            if(i > start && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        backtrack(0, nums, curr);

        return res;
    }
};