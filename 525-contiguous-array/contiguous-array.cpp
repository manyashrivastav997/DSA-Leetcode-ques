#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        // Map to store the first occurrence of a prefix sum: {sum, index}
        std::unordered_map<int, int> sumMap;
        
        // Base case: a sum of 0 is conceptually seen at index -1
        sumMap[0] = -1;
        
        int maxLen = 0;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Treat 0 as -1 and 1 as +1
            currentSum += (nums[i] == 0) ? -1 : 1;
            
            // If the sum has been seen before, calculate the subarray length
            if (sumMap.find(currentSum) != sumMap.end()) {
                maxLen = std::max(maxLen, i - sumMap[currentSum]);
            } else {
                // Otherwise, record the first occurrence of this sum
                sumMap[currentSum] = i;
            }
        }
        
        return maxLen;
    }
};
