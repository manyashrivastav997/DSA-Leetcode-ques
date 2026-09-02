#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(), weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(weights, days, mid)) {
                ans = mid;
                high = mid - 1; // Try for a smaller capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }
        return ans;
    }

private:
    bool isPossible(const std::vector<int>& weights, int days, int capacity) {
        int dayCount = 1;
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                dayCount++;
                currentWeight = weight;
            } else {
                currentWeight += weight;
            }
        }
        return dayCount <= days;
    }
};
