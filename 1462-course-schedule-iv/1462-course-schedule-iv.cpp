class Solution {
public:
	void bfs(int i, int n, vector<vector<int>> &adj, vector<vector<int>>&vc, vector<int> &vis) {
		queue<int> q;
		q.push(i);
		int t;
		while (!q.empty()) {
			t = q.front();
			q.pop();
			if (i != t) {
				vc[i][t] = 1;
			}
			for (auto &it : adj[t]) {
				if (!vis[it]) {
					q.push(it);
					vis[it] = 1;
				}
			}
		}
	}
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
		vector<bool > ans(queries.size());
		vector<vector<int>> vc(n, vector<int>(n));
		vector<vector<int>> adj(n);
		for (int i = 0; i < pre.size(); i++) {
			adj[pre[i][0]].push_back(pre[i][1]);
		}
		vector<int> vis(n);
		for (int i = 0; i < n; i++) {
			bfs(i, n, adj, vc, vis);
			for (int j = 0; j < n; j++) {
				vis[j] = 0;
			}
		}
		// debug((int)ans.size())

		for (int i = 0; i < queries.size(); i++) {
			if (vc[queries[i][0]][queries[i][1]]) {
				ans[i] = true;
			}
		}
		// debug(ans)
		return ans;
	}
};