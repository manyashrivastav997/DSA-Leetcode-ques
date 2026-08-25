#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int max_sum = 0;
        int min_sum = 0;
        int current_max = 0;
        int current_min = 0;
        
        for (int num : nums) {
            // Kadane's algorithm for maximum subarray sum
            current_max = std::max(num, current_max + num);
            max_sum = std::max(max_sum, current_max);
            
            // Kadane's algorithm for minimum subarray sum
            current_min = std::min(num, current_min + num);
            min_sum = std::min(min_sum, current_min);
        }
        
        // Return the maximum of max_sum and the absolute value of min_sum
        return std::max(max_sum, std::abs(min_sum));
    }
};
