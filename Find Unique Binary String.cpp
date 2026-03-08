class Solution {
public:
    void helper(unordered_set<string> &set, string &res, int n, string curr, int i){
        if (i == n) {
            if (!set.count(curr)) res = curr;
            return;
        }
        if (res.empty()) helper(set, res, n, curr + '1', i + 1);
        if (res.empty()) helper(set, res, n, curr + '0', i + 1);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string res;
        unordered_set<string> set;
        for (auto str : nums) set.insert(str);
        helper(set, res, n, "", 0);
        return res;
    }
};
