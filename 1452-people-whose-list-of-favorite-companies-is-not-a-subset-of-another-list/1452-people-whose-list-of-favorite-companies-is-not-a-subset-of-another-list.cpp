class Solution {
public:
	vector<unordered_map<string, int>> v;
	vector<int> peopleIndexes(vector<vector<string>>& A) {
		vector<unordered_map<string, int>> v(A.size());
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				v[i][A[i][j]]++;
			}
		}
		// debug(v)
		vector<int> ans;
		bool ok;
		for (int i = 0; i < A.size(); i++) {
			bool ok = false;
			for (int j = 0; j < A.size(); j++) {
				if (i == j) {
					continue;
				}
				// debug(v[j])

				bool ok1 = false;
				for (int k = 0; k < A[i].size(); k++) {
					if (v[j].find(A[i][k]) == v[j].end()) {
						ok1 = true;
						break;
					}
				}
				if (!ok1) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				ans.push_back(i);
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};
