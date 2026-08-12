class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<int>> best(n, vector<int>(n, 0));

        ways[0][0] = 1;
        best[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // If this cell is unreachable, skip it
                if (ways[i][j] == 0)
                    continue;

                // Move Right
                if ((grid[i][j] == 1 || grid[i][j] == 3) &&
                    j + 1 < n) {

                    ways[i][j + 1] =
                        (ways[i][j + 1] + ways[i][j]) % MOD;

                    best[i][j + 1] =
                        max(best[i][j + 1],
                            best[i][j] + grid[i][j + 1]);
                }

                // Move Down
                if ((grid[i][j] == 2 || grid[i][j] == 3) &&
                    i + 1 < n) {

                    ways[i + 1][j] =
                        (ways[i + 1][j] + ways[i][j]) % MOD;

                    best[i + 1][j] =
                        max(best[i + 1][j],
                            best[i][j] + grid[i + 1][j]);
                }
            }
        }

        // Destination unreachable
        if (ways[n - 1][n - 1] == 0)
            return {0, 0};

        return {
            (int)ways[n - 1][n - 1],
            best[n - 1][n - 1]
        };
    }
};
 
