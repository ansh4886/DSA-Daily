class Solution {
  public:
    bool left(int r,int c,vector<vector<int>>& mat){
        for(int j=c-1;j>=0;j--){
            if(mat[r][j])return true;
        }
        return false;
    }
    bool right(int r,int c,vector<vector<int>>& mat){
        for(int j=c+1;j<mat[0].size();j++){
            if(mat[r][j])return true;
        }
        return false;
    }
    
    bool up(int r,int c,vector<vector<int>>& mat){
        for(int i=r-1;i>=0;i--){
            if(mat[i][c])return true;
        }
        return false;
    }
    
    bool down(int r,int c,vector<vector<int>>& mat){
        for(int i=r+1;i<mat.size();i++){
            if(mat[i][c])return true;
        }
        return false;
    }
    
    int findCoverage(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    result+=left(i,j,mat);
                    result+=right(i,j,mat);
                    result+=up(i,j,mat);
                    result+=down(i,j,mat);
                }
            }
        }
        return result;
    }
};

//GFG POTD solution for 18 June
