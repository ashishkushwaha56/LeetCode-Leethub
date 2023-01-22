class Solution {
public:
	bool helper(string &s, int i, int j) {
		while (i <= j) {
			if (s[i] != s[j]) return false; i++; j--;
		}
		return true;
	}
	void check(vector<vector<string>>&ans, vector<string>&temp, int i, string &s) {
		if (i >= s.size()) {
			ans.push_back(temp);
			return;
		}
		for (int j = i; j < s.size(); j++) {
			if (helper(s, i, j)) {
				temp.push_back(s.substr(i, j - i + 1));
				check(ans, temp, j + 1, s);
				temp.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> temp;
		check(ans, temp, 0, s);
		return ans;
	}
};