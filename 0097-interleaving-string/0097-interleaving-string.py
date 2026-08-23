class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        m, n = len(s1), len(s2)
        
        # Base case check: The lengths must add up
        if m + n != len(s3):
            return False
        
        # Space optimization: ensure s2 is the shorter string
        if m < n:
            s1, s2 = s2, s1
            m, n = n, m
            
        # dp[j] will store whether s3[:i+j] can be formed by s1[:i] and s2[:j]
        dp = [False] * (n + 1)
        dp[0] = True
        
        # Initialize the first row (comparing s2 to s3, assuming 0 chars from s1)
        for j in range(1, n + 1):
            dp[j] = dp[j-1] and s2[j-1] == s3[j-1]
            
        # Fill the DP array row by row
        for i in range(1, m + 1):
            # Update the first column of the current row (0 chars from s2)
            dp[0] = dp[0] and s1[i-1] == s3[i-1]
            
            for j in range(1, n + 1):
                # We can form s3[:i+j] if:
                # 1. We drop a char from s1 (dp[j] is True) AND the current s1 char matches s3
                # 2. We drop a char from s2 (dp[j-1] is True) AND the current s2 char matches s3
                match_s1 = dp[j] and s1[i-1] == s3[i+j-1]
                match_s2 = dp[j-1] and s2[j-1] == s3[i+j-1]
                
                dp[j] = match_s1 or match_s2
                
        return dp[n]