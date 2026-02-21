class Solution {
public:
    
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                ans = mid;         // store answer
                right = mid - 1;   // move left to find earlier occurrence
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                ans = mid;        // store answer
                left = mid + 1;   // move right to find later occurrence
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};