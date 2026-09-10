#include <vector>
#include <set>

class Solution {
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> medians;
        std::multiset<long long> max_heap; // Lower half
        std::multiset<long long> min_heap; // Upper half

        // Helper function to balance the sizes of the two multisets
        auto balance = [&]() {
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.insert(*max_heap.rbegin());
                max_heap.erase(std::prev(max_heap.end()));
            } else if (min_heap.size() > max_heap.size()) {
                max_heap.insert(*min_heap.begin());
                min_heap.erase(min_heap.begin());
            }
        };

        // Helper function to insert an element
        auto add = [&](long long val) {
            if (max_heap.empty() || val <= *max_heap.rbegin()) {
                max_heap.insert(val);
            } else {
                min_heap.insert(val);
            }
            balance();
        };

        // Helper function to remove an element
        auto remove = [&](long long val) {
            auto it = max_heap.find(val);
            if (it != max_heap.end()) {
                max_heap.erase(it);
            } else {
                it = min_heap.find(val);
                if (it != min_heap.end()) {
                    min_heap.erase(it);
                }
            }
            balance();
        };

        // Helper function to get the current median
        auto get_median = [&]() -> double {
            if (k % 2 == 1) {
                return *max_heap.rbegin();
            } else {
                return (*max_heap.rbegin() + *min_heap.begin()) / 2.0;
            }
        };

        // Process the first window
        for (int i = 0; i < k; ++i) {
            add(nums[i]);
        }
        medians.push_back(get_median());

        // Process the remaining windows
        for (int i = k; i < nums.size(); ++i) {
            remove(nums[i - k]); // Remove the element leaving the window
            add(nums[i]);        // Add the element entering the window
            medians.push_back(get_median());
        }

        return medians;
    }
};
