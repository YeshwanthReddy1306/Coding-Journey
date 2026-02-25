class Solution(object):
    def maxSubArray(self, nums):
        current_sum = nums[0]
        max_sum = nums[0]
        
        for i in range(1, len(nums)):
            # Either extend the previous subarray or start new
            current_sum = max(nums[i], current_sum + nums[i])
            
            # Update global maximum
            max_sum = max(max_sum, current_sum)
        
        return max_sum