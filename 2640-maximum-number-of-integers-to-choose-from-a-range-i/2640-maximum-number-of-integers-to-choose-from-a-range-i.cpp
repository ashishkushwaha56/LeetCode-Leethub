class Solution {
public:
	int maxCount(vector<int>& banned, int n, int maxSum) {
		vector<bool> v(*max_element(banned.begin(), banned.end()) + 1, true);
		for (int i = 0; i < banned.size(); i++) {
			v[banned[i]] = false;
		}
		int ans = 0;
		for (int i = 1; i < n + 1; i++) {
			if (i >= v.size()) {
				if (i > maxSum) {
					break;
				}
				maxSum -= i;
				ans++;
			}
			else if (v[i]) {
				if (i > maxSum) {
					break;
				}
				maxSum -= i;
				ans++;
			}
		}
		return ans;
	}
};