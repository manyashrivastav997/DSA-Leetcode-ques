#include <vector>

class Solution {
private:
    void findCombinations(int index, int target, std::vector<int>& candidates, 
                          std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: if out of bounds or target becomes negative
        if (index == candidates.size() || target < 0) {
            return;
        }
        
        // Option 1: Pick the current element
        // We stay at the same index because we can reuse the same element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result);
            current.pop_back(); // Backtrack
        }
        
        // Option 2: Skip the current element and move to the next index
        findCombinations(index + 1, target, candidates, current, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};
