#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0); // Stores frequencies of characters A-Z
        int left = 0;
        int max_count = 0; // Tracks the highest character count in the current window
        int max_length = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Include the current character in the window
            count[s[right] - 'A']++;
            max_count = std::max(max_count, count[s[right] - 'A']);

            // Current window size is (right - left + 1)
            // Number of characters to replace = window size - max_count
            while ((right - left + 1) - max_count > k) {
                // Shrink the window from the left if replacements exceed k
                count[s[left] - 'A']--;
                left++;
            }

            // Update the maximum length of a valid window found
            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;
    }
};
