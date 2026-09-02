#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    bool canSplit(const std::vector<int>& nums, int k, int max_sum) {
        int subarray_count = 1;
        int current_sum = 0;
        
        for (int num : nums) {
            if (current_sum + num > max_sum) {
                subarray_count++;
                current_sum = num;
                if (subarray_count > k) {
                    return false;
                }
            } else {
                current_sum += num;
            }
        }
        return true;
    }

public:
    int splitArray(std::vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        
        for (int num : nums) {
            low = std::max(low, num);
            high += num;
        }
        
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
