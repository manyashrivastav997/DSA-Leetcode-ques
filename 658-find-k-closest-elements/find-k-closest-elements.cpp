#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        // Initialize binary search bounds for the starting index
        int low = 0;
        int high = arr.size() - k;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Compare distance of arr[mid] and arr[mid + k] from x
            // We use long long to prevent any potential integer overflow
            if (static_cast<long long>(x) - arr[mid] > static_cast<long long>(arr[mid + k]) - x) {
                // arr[mid] is further away from x than arr[mid + k], shift window right
                low = mid + 1;
            } else {
                // arr[mid] is closer or equally close to x, shift window left
                high = mid;
            }
        }
        
        // Return the contiguous subarray of length k starting at index 'low'
        return std::vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
