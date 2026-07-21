class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        vector<int> maxReach(26, -1);
        
        int ans = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            int best = i;
            
            if (c < 25 && maxReach[c + 1] != -1) {
                best = maxReach[c + 1];
            }
            
            maxReach[c] = max(maxReach[c], best);
            
            if (c == 0) {
                ans = max(ans, best - i);
            }
        }
        
        return ans;
    }
};
//GFG POTD solution for 21 July
