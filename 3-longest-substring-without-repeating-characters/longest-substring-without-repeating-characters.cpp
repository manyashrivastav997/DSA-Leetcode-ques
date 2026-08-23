#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> last_seen(256, -1);
        int max_len = 0;
        int start = 0; 
        
        for (int i = 0; i < s.length(); ++i) {
            unsigned char current_char = s[i];
            
            if (last_seen[current_char] >= start) {
                start = last_seen[current_char] + 1;
            }
            
            last_seen[current_char] = i;
            max_len = std::max(max_len, i - start + 1);
        }
        
        return max_len;
    }
};
