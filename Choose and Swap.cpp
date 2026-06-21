class Solution {
public:
    string chooseSwap(string &s) {
        int n = s.size();

        vector<int> first(26, -1);
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int c = 0; c < s[i] - 'a'; c++) {
                if (first[c] > i) {
                    char x = s[i];
                    char y = c + 'a';

                    string t = s;
                    for (char &ch : t) {
                        if (ch == x)
                            ch = y;
                        else if (ch == y)
                            ch = x;
                    }

                    if (t < s)
                        return t;
                }
            }
        }

        return s;
    }
};
//GFG POTD solution for 21 June
