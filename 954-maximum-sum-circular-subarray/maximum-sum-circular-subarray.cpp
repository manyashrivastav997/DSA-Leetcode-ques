class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxCurr = 0, maxSum = nums[0];
        int minCurr = 0, minSum = nums[0];
        
        for (int num : nums) {
            // Standard Kadane's for maximum subarray sum
            maxCurr = max(num, maxCurr + num);
            maxSum = max(maxSum, maxCurr);
            
            // Kadane's variant for minimum subarray sum
            minCurr = min(num, minCurr + num);
            minSum = min(minSum, minCurr);
            
            totalSum += num;
        }
        
        // If all numbers are negative, maxSum will be the maximum negative number
        if (maxSum < 0) {
            return maxSum;
        }
        
        // Maximum of normal non-circular sum or circular wrap-around sum
        return max(maxSum, totalSum - minSum);
    }
};
