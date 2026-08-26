#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        // FIXED: Changed .length() to .size()
        int n = nums.size(); 
        
        // Use long long to prevent integer overflow during accumulation
        std::vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        std::deque<int> dq;
        int minLength = n + 1; 
        
        for (int i = 0; i <= n; ++i) {
            // Check if the current sum minus the oldest sum meets the target 'k'
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = std::min(minLength, i - dq.front());
                dq.pop_front(); 
            }
            
            // Maintain the monotonic increasing property of the deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return (minLength == n + 1) ? -1 : minLength;
    }
};
