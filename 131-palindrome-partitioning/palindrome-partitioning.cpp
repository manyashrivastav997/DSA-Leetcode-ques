class Solution {
private:
    bool isPalindrome(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(int index, const std::string& s, std::vector<std::string>& path, std::vector<std::vector<std::string>>& result) {
        if (index == s.length()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.length(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, result);
                path.pop_back(); // backtrack
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        dfs(0, s, path, result);
        return result;
    }
};
