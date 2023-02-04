class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26), b(26);
        if (s1.size() > s2.size()) {
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            v[s1[i] - 'a']++;
        }
        int i = 0;
        while (i < s1.size()) {
            b[s2[i] - 'a']++;
            i++;
        }
        while (i < s2.size()) {
            if (b == v) return true;
            b[s2[i - s1.size()] - 'a']--;
            b[s2[i] - 'a']++;
            i++;
        }
        if (b == v) return true;
        return false;
    }
};