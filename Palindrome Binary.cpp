class Solution {
  public:
  
    bool check(string s){
        int i = 0;
        int j = s.length() - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
  
    int isPallindrome(long long int N) {
        // code here
        string s = "";
        long long int temp = N;
        while(temp > 0){
            int rem = temp % 2;
            s += to_string(rem);
            temp /= 2;
        }
        if(check(s)) return 1;
        
        
        return 0;
    }
};
//GFG POTD solution for 04 May
