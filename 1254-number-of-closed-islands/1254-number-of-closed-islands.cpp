class Solution {
public:
	vector<int> dx = { -1, 1, 0, 0};
	vector<int> dy = {0, 0, -1, 1};
	void dfs(vector<vector<int>>&v, int i, int j, bool &ans) {
		// if (i<0 or j<0 or i >= v.size() or j >= v[0].size()) return false;
		// bool ans = true;
		// if (v[i][j]) return true;
		v[i][j] = 1;
		for (int k = 0; k < 4; k++) {
			if (i + dx[k] < 0 or j + dy[k] < 0 or i + dx[k] >= v.size() or j + dy[k] >= v[0].size()) {ans = false;}

			else if (v[i + dx[k]][j + dy[k]] == 0) {
				dfs(v, i + dx[k], j + dy[k], ans);
				// debug(mp(i, j))
				// debug(ans)
			}
		}
		if (!ans) {
			return;
		}
		// v[i][j] = 0;
		// return ans;
	}
	int closedIsland(vector<vector<int>>& grid) {
		int ans = 0;
		bool ok = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				// debug(mp(i, j))
				// debug(ans)
				if (!grid[i][j]) {
					ok = true;
					dfs(grid, i, j, ok);
					if (ok) ans++;
					// debug(ans)
				}
			}
		}
		return ans;
	}
};