//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int ans = 0;
	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};
	void bfs(int n, int m, int x, int y) {
		queue<pair<int, int>> q;
		pair<int, int> temp;
		int t = 1;
		q.push({x, y});
		int c = 0;
		vector<vector<int>> vis(n, vector<int>(m));
		vis[x][y] = 1;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			t--;
			for (int i = 0; i < 4; i++) {
				if (temp.first + dx[i] >= 0 and temp.first + dx[i] < n and temp.second + dy[i] >= 0 and temp.second + dy[i] < m) {
					if (vis[temp.first + dx[i]][temp.second + dy[i]] != 1) {
						vis[temp.first + dx[i]][temp.second + dy[i]] = 1;
						c++;
						q.push({temp.first + dx[i], temp.second + dy[i]});
					}
				}
			}
			if (t == 0) {
				t = c;
				c = 0;
				ans++;
			}
		}

	}
	int minIteration(int N, int M, int x, int y) {
		bfs(N, M, x - 1, y - 1);
		return ans-1;
	}
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends