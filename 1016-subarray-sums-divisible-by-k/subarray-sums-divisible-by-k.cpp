#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        // Frequency array to store remainder counts
        // Using a vector instead of unordered_map for faster access
        std::vector<int> remainder_count(k, 0);
        
        // Base case: a prefix sum of 0 has a remainder of 0
        remainder_count[0] = 1;
        
        int prefix_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            
            // Handle negative remainders to keep them in range [0, k-1]
            int rem = prefix_sum % k;
            if (rem < 0) {
                rem += k;
            }
            
            // If this remainder has been seen before, it forms valid subarrays
            count += remainder_count[rem];
            
            // Increment the frequency of the current remainder
            remainder_count[rem]++;
        }
        
        return count;
    }
};
