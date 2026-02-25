class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // If current index is beyond reachable range → stuck
            if (i > farthest) {
                return false;
            }
            
            // Update farthest reachable index
            farthest = max(farthest, i + nums[i]);
        }
        
        return true;
    }
};