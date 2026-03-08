class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        const int MAX = 1000;
        vector<int> freq(MAX + 1, 0);

        for(int x : arr)
            freq[x]++;

        for(int a = 1; a <= MAX; a++) {
            if(freq[a] == 0) continue;

            for(int b = a; b <= MAX; b++) {
                if(freq[b] == 0) continue;

                int c2 = a*a + b*b;
                int c = sqrt(c2);

                if(c*c == c2 && c <= MAX && freq[c] > 0) {
                    if(a == b && freq[a] < 2) continue;
                    if(a == c && freq[a] < 2) continue;
                    if(b == c && freq[b] < 2) continue;
                    return true;
                }
            }
        }

        return false;
    }
};
//GFG POTD solution for 08 March
