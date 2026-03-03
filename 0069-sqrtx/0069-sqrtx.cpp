class Solution {
public:
    int mySqrt(int x) {
        
        if (x == 0 || x == 1)
            return x;
        
        long left = 1, right = x;
        long ans = 0;
        
        while (left <= right) {
            
            long mid = left + (right - left) / 2;
            
            if (mid <= x / mid) {
                ans = mid;          // possible answer
                left = mid + 1;     // try bigger
            } else {
                right = mid - 1;    // too big
            }
        }
        
        return ans;
    }
};