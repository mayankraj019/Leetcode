#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        std::vector<int> target_freq(128, 0);
        std::vector<int> window_freq(128, 0);

        for (char c : t) {
            target_freq[c]++;
        }

        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (target_freq[i] > 0) required++;
        }

        int l = 0, r = 0;
        int formed = 0;
        int min_len = INT_MAX;
        int min_left = 0;

        while (r < s.length()) {
            char c = s[r];
            window_freq[c]++;

            if (target_freq[c] > 0 && window_freq[c] == target_freq[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];
                
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_left = l;
                }

                window_freq[c]--;
                if (target_freq[c] > 0 && window_freq[c] < target_freq[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};