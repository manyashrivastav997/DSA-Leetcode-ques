#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency array for characters in t
        std::vector<int> targetCount(128, 0);
        for (char c : t) {
            targetCount[c]++;
        }

        // Frequency array for characters in the current window
        std::vector<int> windowCount(128, 0);

        int left = 0;
        int minLeft = 0;
        int minLen = INT_MAX;
        int requiredMatches = 0;
        
        // Count unique characters in t that need to be matched
        int totalUniqueToMatch = 0;
        for (int count : targetCount) {
            if (count > 0) totalUniqueToMatch++;
        }

        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s[right];
            windowCount[rightChar]++;

            // If the character matches the required frequency in t
            if (targetCount[rightChar] > 0 && windowCount[rightChar] == targetCount[rightChar]) {
                requiredMatches++;
            }

            // Shrink the window from the left if all conditions are met
            while (requiredMatches == totalUniqueToMatch) {
                // Update the minimum window metrics
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;

                // If removing the left character breaks the match requirement
                if (targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]) {
                    requiredMatches--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
