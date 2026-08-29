#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, -1);
        std::stack<int> st; // Stores indices

        // Loop twice to simulate the circular array
        for (int i = 0; i < 2 * n; ++i) {
            int currentIndex = i % n;
            
            // Maintain a decreasing stack
            while (!st.empty() && nums[st.top()] < nums[currentIndex]) {
                result[st.top()] = nums[currentIndex];
                st.pop();
            }
            
            // Only push indices from the first pass
            if (i < n) {
                st.push(currentIndex);
            }
        }
        
        return result;
    }
};
