#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(102, 0);
        for (int num : nums) {
            count[num + 1]++;
        }
        for (int i = 1; i <= 100; ++i) {
            count[i] += count[i - 1];
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = count[nums[i]];
        }
        return res;
    }
};