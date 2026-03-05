class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), count1 = 0, count2 = 0;
        string temp1 = s, temp2 = s;
        for (int i = 0; i < n; i++) {
            temp1[i] = i % 2 ? '1' : '0', count1 += temp1[i] != s[i];
        }
        for (int i = 0; i < n; i++) {
            temp2[i] = i % 2 ? '0' : '1', count2 += temp2[i] != s[i];
        }
        return min(count1, count2);
    }
};
