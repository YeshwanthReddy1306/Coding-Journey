class Solution(object):
    def hasValidPath(self, grid):
        m, n = len(grid), len(grid[0])
        
        if (m + n - 1) % 2 != 0 or grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False
            
        dp = [0] * n
        dp[0] = 1 << 1
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                cur = 0
                if i > 0:
                    cur |= dp[j]
                if j > 0:
                    cur |= dp[j - 1]
                    
                if grid[i][j] == '(':
                    dp[j] = cur << 1
                else:
                    dp[j] = cur >> 1
                    
        return bool(dp[-1] & 1)