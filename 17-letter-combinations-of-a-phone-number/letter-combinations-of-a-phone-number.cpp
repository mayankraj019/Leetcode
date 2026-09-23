#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        const std::vector<std::string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        std::vector<std::string> result;
        std::string current = "";

        backtrack(digits, 0, current, pad, result);
        return result;
    }

private:
    void backtrack(const std::string& digits, int index, std::string& current,
                   const std::vector<std::string>& pad, std::vector<std::string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        const std::string& letters = pad[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, pad, result);
            current.pop_back();
        }
    }
};