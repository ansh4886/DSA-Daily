class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
       sort(arr.begin(), arr.end());
       int result = 0;
       int diff = 0;
       for(int i = 0; i < n; i++) {
           while(arr[i] - arr[diff] >= k) {
               diff++;
           }
           result += (i - diff);
       }
       return result;
    }
};
//GFG POTD solution for 04 August
