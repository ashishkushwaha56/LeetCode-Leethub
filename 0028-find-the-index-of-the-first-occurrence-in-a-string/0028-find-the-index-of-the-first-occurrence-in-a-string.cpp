class Solution {
public:
    int strStr(string s, string t) {
        if(s.size()<t.size()) return -1;
        bool ok = false;
	bool ok1 = true;
	int l = -1;
	for (int i = 0; i < s.size() - t.size() + 1; i++) {
		// ok = false;
		if (s[i] == t[0]) {
			ok1 = true;
			for (int j = 0; j < t.size(); j++) {
				if (s[j + i] != t[j]) {
					ok1 = false;
					break;
				}
			}
			if (ok1) {
				ok = true;
				l = i;
				break;
			}
		}
	}
        return l;
    }
};