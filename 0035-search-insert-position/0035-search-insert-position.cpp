class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // avoids overflow
            
            if (nums[mid] == target) {
                return mid;  // target found
            }
            else if (nums[mid] < target) {
                left = mid + 1;   // search right half
            }
            else {
                right = mid - 1;  // search left half
            }
        }
        
        // When loop ends, left is the correct insert position
        return left;
    }
};