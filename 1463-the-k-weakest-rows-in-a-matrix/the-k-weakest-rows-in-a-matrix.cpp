#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        int m = mat.size();
        std::vector<std::pair<int, int>> rows(m); 

        for (int i = 0; i < m; ++i) {
            // Count the number of 1's in the row
            int count = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            rows[i] = {count, i};
        }

        // Sort based on soldier count first, then by row index
        std::sort(rows.begin(), rows.end());

        std::vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = rows[i].second;
        }

        return result;
    }
};
