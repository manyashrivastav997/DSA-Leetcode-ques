#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_so_far = nums[0];
        int current_max = nums[0];
        
        // Changed type to size_t (or you can use int)
        for (std::size_t i = 1; i < nums.size(); ++i) {
            // Decide to either add current element to current subarray, or start a new subarray
            current_max = std::max(nums[i], current_max + nums[i]);
            // Update the overall maximum found so far
            max_so_far = std::max(max_so_far, current_max);
        }
        
        return max_so_far;
    }
};
