#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (size_t i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            
            // If the current element is negative, swapping max and min 
            // accounts for the sign flip when multiplied.
            if (curr < 0) {
                std::swap(max_so_far, min_so_far);
            }

            // The choice is either to start a new subarray at the current element,
            // or continue the existing subarray.
            max_so_far = std::max(curr, max_so_far * curr);
            min_so_far = std::min(curr, min_so_far * curr);

            // Update the overall maximum product found so far.
            result = std::max(result, max_so_far);
        }

        return result;
    }
};
