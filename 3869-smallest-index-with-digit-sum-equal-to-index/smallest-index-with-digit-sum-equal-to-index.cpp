#include <vector>

class Solution {
public:
    int smallestIndex(std::vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int n = nums[i];
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};