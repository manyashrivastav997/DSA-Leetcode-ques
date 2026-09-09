#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // Count frequencies of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Push all characters with their counts into a max-heap
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // If any character frequency exceeds the limit, it's impossible
                if (freq[i] > (s.length() + 1) / 2) {
                    return "";
                }
                maxHeap.push({freq[i], 'a' + i});
            }
        }
        
        string result = "";
        
        // Process two characters at a time to prevent adjacent duplicates
        while (maxHeap.size() >= 2) {
            auto first = maxHeap.top(); maxHeap.pop();
            auto second = maxHeap.top(); maxHeap.pop();
            
            result += first.second;
            result += second.second;
            
            if (--first.first > 0) maxHeap.push(first);
            if (--second.first > 0) maxHeap.push(second);
        }
        
        // Append the last remaining character if there is one
        if (!maxHeap.empty()) {
            result += maxHeap.top().second;
        }
        
        return result;
    }
};
