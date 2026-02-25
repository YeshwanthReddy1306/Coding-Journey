class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either start new subarray or continue previous one
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Update global maximum
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};