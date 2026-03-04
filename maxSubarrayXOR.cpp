class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        if(k<=0||k>arr.size()) return 0;
        int xorr=0;
        for(int i=0;i<k;i++){
            xorr=xorr^arr[i];
        }
        int maxi=xorr;
        for(int i=k;i<arr.size();i++){
            xorr=xorr^arr[i-k];
            xorr=xorr^arr[i];
            maxi=max(maxi,xorr);
        }
        return maxi;
    }
};
//GFG POTD solution for 04 March
