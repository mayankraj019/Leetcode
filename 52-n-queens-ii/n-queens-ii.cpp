class Solution {
    void backtrack(int row, int n, int cols, int diag1, int diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int p = available & -available;
            available -= p;
            backtrack(row + 1, n, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, count);
        }
    }
public:
    int totalNQueens(int n) {
        int count = 0;
        backtrack(0, n, 0, 0, 0, count);
        return count;
    }
};
