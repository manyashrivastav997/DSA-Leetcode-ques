#include <algorithm>

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (enough(mid, m, n, k)) {
                ans = mid;
                right = mid - 1; // Try to find a smaller valid number
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
private:
    bool enough(int x, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += std::min(n, x / i);
        }
        return count >= k;
    }
};
