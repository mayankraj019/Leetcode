#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> char_index;
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            if (char_index.count(current_char) && char_index[current_char] >= left) {
                left = char_index[current_char] + 1;
            }
            char_index[current_char] = right;
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};