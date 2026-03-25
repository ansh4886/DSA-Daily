class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0, curr1 = 0, curr2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            curr1 += rowSum[i];
            if (curr1 * 2 == total) return true;
        }
        for (int j = 0; j < n; j++) {
            curr2 += colSum[j];
            if (curr2 * 2 == total) return true;
        }
        return false;
    }
};
