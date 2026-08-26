#include <vector>
#include <algorithm>

class Solution {
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // Use long long to prevent integer overflow during prefix sum calculations
        std::vector<long long> prefix_sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }
        return mergeSortCount(prefix_sums, 0, n, lower, upper);
    }

private:
    int mergeSortCount(std::vector<long long>& sums, int left, int right, int lower, int upper) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        // Recursively count combinations in left and right halves
        int count = mergeSortCount(sums, left, mid, lower, upper) + 
                    mergeSortCount(sums, mid + 1, right, lower, upper);
        
        // Two-pointer approach to count valid range sums crossing the midpoint
        int start = left, end = left;
        for (int j = mid + 1; j <= right; ++j) {
            while (start <= mid && sums[j] - sums[start] > upper) {
                start++;
            }
            while (end <= mid && sums[j] - sums[end] >= lower) {
                end++;
            }
            count += (end - start);
        }
        
        // Merge the two already sorted halves in-place
        std::inplace_merge(sums.begin() + left, sums.begin() + mid + 1, sums.begin() + right + 1);
        
        return count;
    }
};
