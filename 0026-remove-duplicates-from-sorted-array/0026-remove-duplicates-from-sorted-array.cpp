/*
Time Complexity:
- We traverse the array once.
Overall: O(n)

Space Complexity:
- No extra data structures used.
- Modification is done in-place.
Overall: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int i = 0;  // Pointer for placing unique elements
        
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;  // Number of unique elements
    }
};
