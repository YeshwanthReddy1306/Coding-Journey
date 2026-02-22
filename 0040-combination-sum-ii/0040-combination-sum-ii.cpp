class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            
            // Prune if number exceeds target
            if (candidates[i] > target)
                break;
            
            current.push_back(candidates[i]);
            
            // Move to next index (i+1) because we can't reuse same element
            solve(i + 1, candidates, target - candidates[i], current, result);
            
            current.pop_back(); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, current, result);
        
        return result;
    }
};