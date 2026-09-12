#include <vector>
#include <string>

class Solution {
private:
    // Mapping of digits to letters corresponding to telephone buttons
    const std::vector<std::string> PHONE_MAP = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters associated with the current digit
        std::string letters = PHONE_MAP[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);          // Choose the letter
            backtrack(digits, index + 1, current, result); // Recurse for the next digit
            current.pop_back();                 // Backtrack (remove the letter)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Edge case: empty input
        if (digits.empty()) {
            return result;
        }
        
        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};
