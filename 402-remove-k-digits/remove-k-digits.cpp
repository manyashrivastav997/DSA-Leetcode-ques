class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string res = "";
        
        for (char digit : num) {
            // Remove larger preceding digits to keep the number as small as possible
            while (k > 0 && !res.empty() && res.back() > digit) {
                res.pop_back();
                k--;
            }
            res.push_back(digit);
        }
        
        // If k is still greater than 0, remove digits from the end
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int firstNonZero = 0;
        while (firstNonZero < res.length() && res[firstNonZero] == '0') {
            firstNonZero++;
        }
        
        res = res.substr(firstNonZero);
        
        // If the result is empty, return "0"
        return res.empty() ? "0" : res;
    }
};
