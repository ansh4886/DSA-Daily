class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;
        vector<int> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // size 0 rhombus
                st.insert(grid[i][j]);
                for(int k = 1; ; k++) {
                    int r = i + 2 * k;
                    int left = j - k, right = j + k;
                    int sum = 0;
                    int x = i, y = j;
                    if(r >= m || left < 0 || right >= n) break;
                    // top -> right
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }
                    // right -> bottom
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }
                    // bottom -> left
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + 2*k - t][y - t];
                    }
                    // left -> top
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }
                    st.insert(sum);
                }
            }
        }
        for(auto it = st.rbegin(); it != st.rend() && res.size() < 3; ++it) res.push_back(*it);
        return res;
    }
};
