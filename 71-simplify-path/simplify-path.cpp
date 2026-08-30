#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st;
        std::stringstream ss(path);
        std::string dir;

        while (std::getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(dir);
            }
        }

        std::string result = "";
        for (const std::string& s : st) {
            result += "/" + s;
        }

        return result.empty() ? "/" : result;
    }
};
