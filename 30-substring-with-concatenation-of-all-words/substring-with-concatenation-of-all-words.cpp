#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        if (s.empty() || words.empty()) return res;
        
        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        if (s.length() < total_len) return res;
        
        std::unordered_map<std::string, int> word_count;
        for (const std::string& w : words) {
            word_count[w]++;
        }
        
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string, int> seen;
            int count = 0;
            
            while (right + word_len <= s.length()) {
                std::string sub = s.substr(right, word_len);
                right += word_len;
                
                if (word_count.find(sub) != word_count.end()) {
                    seen[sub]++;
                    count++;
                    
                    while (seen[sub] > word_count[sub]) {
                        std::string left_sub = s.substr(left, word_len);
                        seen[left_sub]--;
                        count--;
                        left += word_len;
                    }
                    
                    if (count == num_words) {
                        res.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return res;
    }
};
