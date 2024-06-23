class Solution {
public:
	vector<int> dx = { -1, 1, 0, 0};
	vector<int> dy = {0, 0, -1, 1};
	int dfs(vector<vector<int>>&v, int i, int j, bool &ans) {
		if (i<0 or j<0 or i >= v.size() or j >= v[0].size()) {ans = false; return 0;}

		if (!v[i][j]) return 0;
		int cnt = 0;
		v[i][j] = 0;
		for (int k = 0; k < 4; k++) {
			cnt += dfs(v, i + dx[k], j + dy[k], ans);
		}
		return (1 + cnt);
	}
	int numEnclaves(vector<vector<int>>&grid) {
		int ans = 0;
		bool ok = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				ok = true;
				if (grid[i][j] == 1) {
					int cnt = dfs(grid, i, j, ok);
					if (ok) {
						ans += cnt;
					}
				}
			}
		}
		return ans;
	}
};