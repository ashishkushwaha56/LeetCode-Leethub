class Solution {
public:
	set<vector<int>> ans;
	void check(vector<int>&v, int i, vector<int>&temp) {
		if (i >= v.size()) {
			if (temp.size() >= 2) {
				ans.insert(temp);
			}
			return;
		}
		// int j = i;
		// while (j + 1 < v.size() and v[j] == v[j + 1]) {
		// 	j++;
		// }
		// temp.push_back(v[j]);
		// check(v, j + 1, temp);
		// temp.pop_back();
		if (temp.empty()) {
			temp.push_back(v[i]);
			check(v, i + 1, temp);
			temp.pop_back();
			check(v, i + 1, temp);
		}
		else {
			if (temp.back() <= v[i]) {
				temp.push_back(v[i]);
				check(v, i + 1, temp);
				temp.pop_back();
				check(v, i + 1, temp);
			}
			else {
				check(v, i + 1, temp);
			}
		}

		// while (i + 1 < v.size() and v[i] == v[i + 1]) {
		// 	i++;
		// }
		// temp.push_back(v[i + 1]);
		// check(v, i + 1, temp);

	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> temp;
		check(nums, 0, temp);
		vector<vector<int>> b;
		for (auto &it : ans) {
			b.push_back(it);
		}
		return b;
	}
};