#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // The search space for speed k ranges from 1 to the largest pile size
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Calculate total hours needed at speed 'mid'
            long long total_hours = 0;
            for (int pile : piles) {
                // Ceiling division: (pile + mid - 1) / mid
                total_hours += (pile + mid - 1) / mid;
            }
            
            // If Koko can finish within h hours, try a slower speed
            if (total_hours <= h) {
                right = mid;
            } else {
                // If she takes too long, she must eat faster
                left = mid + 1;
            }
        }
        
        return left;
    }
};
