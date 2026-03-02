class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.empty()) 
            return {};
        
        // Step 1: Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        // Step 2: Start with first interval
        vector<int> current = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            
            // If overlapping
            if (intervals[i][0] <= current[1]) {
                // Merge by updating end time
                current[1] = max(current[1], intervals[i][1]);
            } 
            else {
                // No overlap → push current interval
                result.push_back(current);
                current = intervals[i];
            }
        }
        
        // Push the last interval
        result.push_back(current);
        
        return result;
    }
};