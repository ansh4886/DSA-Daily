class Solution {
  public:
    // method returns true if string
    // contains valid parenthesis
    bool isValidString(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    }

    // function to remove invalid parenthesis
    vector<string> validParenthesis(string &s) {

        // to ignore already visited string
        unordered_map<string, int> visit;

        // queue to maintain BFS
        queue<string> q;

        // to store the valid strings
        vector<string> res;
        bool level = false;

        // pushing given string as starting node into queue
        q.push(s);

        // mark the string as visited
        visit[s] = 1;

        // while queue is not empty
        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            // check if the string is valid
            if (isValidString(temp)) {

                // if valid, store it
                res.push_back(temp);

                // make level true, so that valid string
                // of only that level are processed.
                level = true;
            }

            if (level)
                continue;

            for (int i = 0; i < temp.length(); i++) {

                // if current character is not a parenthesis
                // continue to next character
                if (temp[i] != '(' && temp[i] != ')')
                    continue;

                // Removing parenthesis and pushing into queue
                string cur = temp.substr(0, i) + temp.substr(i + 1);

                if (visit.count(cur) == 0) {
                    q.push(cur);
                    visit[cur] = 1;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
