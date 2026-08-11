class Solution {
  public:
    virtual bool isValid(int i, int j, vector<vector<int>> &psum, int k, int curSize){
      int n=psum.size(), m=psum[0].size();
      
      int ui=i+curSize, uj=j+curSize; 
      int li=i-curSize, lj=j-curSize; 
      
      if(li<0 || lj<0 || ui>=n || uj>=m) return false;
      
      int count1s = psum[ui][uj]; 
      if(lj>0) count1s-=psum[ui][lj-1];
      if(li>0) count1s-=psum[li-1][uj];
      if(li>0 && lj>0) count1s+=psum[li-1][lj-1];
      
      return count1s<=k;
    }
    
    virtual vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k){
      vector<int> ans;
      
      int n=mat.size(), m=mat[0].size();
      
      
      //PrefSum Logic
      vector<vector<int>> psum(n, vector<int>(m, 0));
      psum[0][0]=mat[0][0];
      for(int i=1; i<m; i++) psum[0][i]=mat[0][i]+psum[0][i-1];
      for(int i=1; i<n; i++) psum[i][0]=mat[i][0]+psum[i-1][0];
      
      for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
          psum[i][j] = mat[i][j] 
                     + (i > 0 ? psum[i-1][j] : 0) 
                     + (j > 0 ? psum[i][j-1] : 0) 
                     - (i > 0 && j > 0 ? psum[i-1][j-1] : 0);    
        }  
      }
      
      
      for(auto v: queries){
        int curSize=0;
        int i=v[0], j=v[1];
        
        while(isValid(i, j, psum, k, curSize)){curSize++;}
        
        
        ans.push_back(2*curSize-1);
      }
      
      return ans;
      
      
    }
};


//GFG POTD solution for 11 August
