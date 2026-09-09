#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Create a max-heap from the stones array
        std::priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // Process stones until 0 or 1 stone remains
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); // Heaviest stone
            maxHeap.pop();
            
            int x = maxHeap.top(); // Second heaviest stone
            maxHeap.pop();
            
            // If they are not equal, push the remaining weight back
            if (x != y) {
                maxHeap.push(y - x);
            }
        }
        
        // Return the last remaining stone weight, or 0 if empty
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
