class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int>incom(n,0);
        vector<int>adj[n];
        for(auto i:prereq){
            adj[i[0]].push_back(i[1]);
            incom[i[1]]++;
        }
        queue<int>qu;
        for(auto i=0;i<n;i++){
            if(incom[i]==0){
                qu.push(i);
            }
        }
        int step=0;
        while(!qu.empty()){
            int val=qu.front();
            step++;
            qu.pop();
            for(auto i:adj[val]){
                incom[i]--;
                if(incom[i]==0){
                    qu.push(i);
                }
            }
            
        }
        return step==n?1:0;
    }
};
//GFG POTD solution for 24 March
