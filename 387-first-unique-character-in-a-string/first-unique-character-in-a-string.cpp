#include <string>
#include <vector>

class Solution {
public:
    int firstUniqChar(std::string s) {
        // Frequency array for 26 lowercase English letters
        std::vector<int> count(26, 0);
        
        // Count occurrences of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Find the first character with a count of 1
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
