class Solution {
public:
    bool check(string &a, string &b, string t) {
		if (a.size() % t.size() != 0 or b.size() % t.size() != 0) return false;
		for (int i = 0; i < a.size(); i += t.size()) {
			for (int j = 0; j < t.size(); j++) {
				if (a[i + j] != t[j]) return false;
			}
		}
		for (int i = 0; i < b.size(); i += t.size()) {
			for (int j = 0; j < t.size(); j++) {
				if (b[i + j] != t[j]) return false;
			}
		}
		return true;
	}
    string gcdOfStrings(string s1, string s2) {
        string ans = "";
		if (s1.size() < s2.size()) {
			int i = 0;
			while (i < s1.size()) {
				if (check(s1, s2, s1.substr(0, i + 1))) {
					ans = s1.substr(0, i + 1);
				}
				i++;
			}
		}
		else {
			int i = 0;
			while (i < s2.size()) {
				if (check(s1, s2, s2.substr(0, i + 1))) {
					ans = s2.substr(0, i + 1);
				}
				i++;
			}
		}
		return ans;
    }
};