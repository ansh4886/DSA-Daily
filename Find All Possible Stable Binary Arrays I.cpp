class Solution {
public:
    const int MOD = 1e9 + 7;
    int helper(vector<vector<vector<int>>> &dp, int zero, int one, int limit, int flag){
        if (!zero && !one) return 1;
        if ((!zero && one > limit) || (zero > limit && !one)) return 0;
        if (dp[zero][one][flag] != -1) return dp[zero][one][flag];
        int res = 0;
        if (!flag){
            for (int i = 1; i <= min(zero, limit); i++) {
                res = (res + helper(dp, zero - i, one, limit, 1)) % MOD;
            }
        }
        else{
            for (int i = 1; i <= min(one, limit); i++) {
                res = (res + helper(dp, zero, one - i, limit, 0)) % MOD;
            }
        }
        return dp[zero][one][flag] = res % MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>> (one + 1, vector<int> (2, -1)));
        return (helper(dp, zero, one, limit, 0) + helper(dp, zero, one, limit, 1)) % MOD;
    }
};
