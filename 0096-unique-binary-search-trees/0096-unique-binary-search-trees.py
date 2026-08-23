class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Calculate combinations for (2n) choose (n)
        ans = 1
        for i in range(1, n + 1):
            ans = ans * (n + i) // i
        
        # Divide by (n + 1) to derive the Catalan number
        return ans // (n + 1)