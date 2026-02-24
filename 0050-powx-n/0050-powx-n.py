class Solution(object):
    def myPow(self, x, n):
        
        # Handle negative exponent
        if n < 0:
            x = 1 / x
            n = -n
        
        result = 1
        
        while n > 0:
            
            # If n is odd
            if n % 2 == 1:
                result *= x
            
            # Square the base
            x *= x
            
            # Divide exponent by 2
            n //= 2
        
        return result