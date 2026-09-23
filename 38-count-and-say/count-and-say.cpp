#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string current = "1";

        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int len = current.length();

            for (int j = 0; j < len; ++j) {
                int count = 1;
                while (j + 1 < len && current[j] == current[j + 1]) {
                    ++count;
                    ++j;
                }
                next += std::to_string(count);
                next += current[j];
            }

            current = std::move(next);
        }

        return current;
    }
};