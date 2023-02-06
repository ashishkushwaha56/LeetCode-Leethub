class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (count(target.begin(), target.end(), '1') == 0) {
            if (count(s.begin(), s.end(), '1') != 0) return false;
            return true;
        }
        if (count(target.begin(), target.end(), '0') == 0) {
            if (count(s.begin(), s.end(), '1') == 0) return false;
            return true;
        }
        if (count(s.begin(), s.end(), '1') == 0) {
            if (count(target.begin(), target.end(), '1') != 0) return false;
            return true;
        }
        if (count(s.begin(), s.end(), '0') == 0) {
            if (count(target.begin(), target.end(), '1') == 0) return false;
            return true;
        }
        return true;
    }
};