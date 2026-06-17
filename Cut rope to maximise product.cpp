class Solution {
  public:
    vector<int> dp;
        
    int solve(int n)
    {
        if(n==1) return 1;
        
        int& t = dp[n];
        if(t != -1) return t;
        
        int ans = 1;
        for(int i=1; i<=n; i++)
        {
            int x = i*solve(n-i);
            ans = max(ans, x);
        }
        return dp[n] = ans;
    }
    
    
    int maxProduct(int n) {
        // code here
        if(n==2) return 1;
        if(n==3) return 2;
        dp.assign(n+1, -1);
        
        return solve(n);
    }
};
//GFG POTD solution for 17 June
