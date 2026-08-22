#include <iostream>
#include <unordered_set>

class Solution {
private:
    // Helper function to calculate the sum of the squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        
        // Loop until n becomes 1 or we find a cycle
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
};
