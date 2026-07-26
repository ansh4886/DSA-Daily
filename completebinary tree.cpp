class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            while(size>0){
                int ind=q.front();
                q.pop();
                level.push_back(arr[ind]);
                if((2*ind+1)<n)
                    q.push(2*ind+1);
                if((2*ind+2)<n)
                    q.push(2*ind+2);
                size--;    
            }
            sort(level.begin(),level.end());
            ans.push_back(level);
        }
        return ans;
    }
};

//GFG POTD solution for 26 July
