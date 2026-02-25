class Solution(object):
    def canJump(self, nums):
        farthest = 0
        
        for i in range(len(nums)):
            # If current index is beyond reachable range → stuck
            if i > farthest:
                return False
            
            # Update farthest reachable index
            farthest = max(farthest, i + nums[i])
        
        return True