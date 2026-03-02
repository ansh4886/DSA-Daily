class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), swaps = 0;
        vector<int> trailing(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            trailing[i] = count;
        }
        for (int i = 0; i < n; i++) {
            int required = n - 1 - i, j = i;
            while (j < n && trailing[j] < required) j++;
            if (j == n) return -1;
            swaps += j - i;
            while (j > i) swap(trailing[j], trailing[j - 1]), j--;
        }
        return swaps;
    }
};
