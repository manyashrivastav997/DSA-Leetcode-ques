#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If descending, peak is on the left side (including mid)
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } 
            // If ascending, peak is on the right side
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
