class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found = false, in_window = false;
        for (char ch : s){
            if (ch == '1'){
                if (!in_window && found) return false;
                else if (!found) found = true, in_window = true; 
            }
            else{
                if (in_window) in_window = false;
            }
        }
        return true;
    }
};
