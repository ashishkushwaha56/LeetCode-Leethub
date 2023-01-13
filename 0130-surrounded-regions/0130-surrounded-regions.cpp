class Solution {
public:
	void bfs(vector<vector<char>>&v, vector<pair<int, int>>&ind, int i, int j, bool &flag, vector<vector<int>>&vis) {
		queue<pair<int, int>> q;
		q.push({i, j});
		pair<int, int> temp;
		vis[i][j] = 1;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			ind.push_back({temp.first, temp.second});
			if (temp.first == 0 or temp.first == v.size() - 1) {
				flag = 0;
			}
			if (temp.second == 0 or temp.second == v[0].size() - 1) {
				flag = 0;
			}
			if (temp.first + 1 < v.size()) {
				if (v[temp.first + 1][temp.second] == 'O' and !vis[temp.first + 1][temp.second]) {
					q.push({temp.first + 1, temp.second});
					vis[temp.first + 1][temp.second] = 1;
				}
			}
			if (temp.first - 1 >= 0) {
				if (v[temp.first - 1][temp.second] == 'O' and !vis[temp.first - 1][temp.second]) {
					q.push({temp.first - 1, temp.second});
					vis[temp.first - 1][temp.second] = 1;
				}
			}
			if (temp.second + 1 < v[0].size()) {
				if (v[temp.first][temp.second + 1] == 'O' and !vis[temp.first][temp.second + 1]) {
					q.push({temp.first, temp.second + 1});
					vis[temp.first][temp.second + 1] = 1;
				}
			}
			if (temp.second - 1 >= 0) {
				if (v[temp.first][temp.second - 1] == 'O' and !vis[temp.first][temp.second - 1]) {
					q.push({temp.first, temp.second - 1});
					vis[temp.first][temp.second - 1] = 1;
				}
			}
		}
	}
	void solve(vector<vector<char>>& board) {
		vector<pair<int, int>> ind;
		vector<vector<int>> vis(board.size(), vector<int>(board[0].size()));
		// for(int i = 0;i<board.size();i++){
		// 	for(int j = 0;j<board[i].size();j++){
		// 		if(board[i][j] == 'X'){
		// 			vis[i][j] = 1;
		// 		}
		// 	}
		// }
		// debug(vis)
		bool flag = true;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'O'  and !vis[i][j]) {
					flag = true;
					bfs(board, ind, i, j, flag, vis);
					if (flag) {
						for (int k = 0; k < ind.size(); k++) {
							board[ind[k].first][ind[k].second] = 'X';
						}
					}
					ind.clear();
				}
			}
		}

	}
};