class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (target < 0) return;
        
        for (int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], current, result);
            current.pop_back();  // backtrack
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0, candidates, target, current, result);
        return result;
    }
};