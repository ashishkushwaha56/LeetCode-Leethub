class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		if (p.size() > s.size()) return {};
		vector<int> v(26), b(26);
		for (int i = 0; i < p.size(); i++) {
			v[p[i] - 'a']++;
		}
		int i = 0;
		while (i < p.size()) {
			b[s[i] - 'a']++;
			i++;
		}
		while (i < s.size()) {
			if (b == v) {
				ans.push_back(i - p.size());
			}
			b[s[i] - 'a']++;
			b[s[i - p.size()] - 'a']--;
			i++;
		}
		if (b == v) {
			ans.push_back(i - p.size());
		}
		return ans;
	}
};