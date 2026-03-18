class Solution {
   public:
    int distCandy(Node* root) {
        int ans = 0;
        function<int(Node*)> f = [&](Node* u) {
            if (!u) return 0;
            auto l = f(u->left);
            auto r = f(u->right);
            ans += abs(l) + abs(r);
            return u->data - 1 + l + r;
        };
        f(root);
        return ans;
    }
};



//GFG POTD solution for 18 March
