class Solution {
  public:
    int findIndex(string &s) {
        return count(s.begin(), s.end(), ')');
    }
};
//GFG POTD solution for 11 June
