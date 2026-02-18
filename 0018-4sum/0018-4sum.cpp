/*
Time Complexity:
- Sorting: O(n log n)
- Two nested loops: O(n^2)
- Two pointer scan inside: O(n)
Overall: O(n^3)

Space Complexity:
- Auxiliary space: O(1)
- Sorting stack space: O(log n)
- Output space: O(k)   (k = number of quadruplets, worst case O(n^3))
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        int n = nums.size();
        
        if(n < 4) return result;
        
        sort(nums.begin(), nums.end());   // O(n log n)
        
        for(int i = 0; i < n - 3; i++) {
            
            // Skip duplicate for first element
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < n - 2; j++) {
                
                // Skip duplicate for second element
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while(left < right) {
                    
                    long long sum = (long long)nums[i] 
                                  + nums[j] 
                                  + nums[left] 
                                  + nums[right];
                    
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        left++;
                        right--;
                        
                        // Skip duplicates
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};
