//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int bfs(vector<int> adj[],int V,int X){
		vector<int> vis(V+1);
		queue<int> q;
		q.push(0);
		int temp;
		int t  = 1;
		int c = 0;
		int ans = 0;
		vis[0] = 1;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			
			if(temp ==X){
				return ans;
			}
			t--;
			for(auto &it:adj[temp]){
				if(!vis[it]){
					vis[it] = 1;
					q.push(it);
					c++;
				}
			}
			if(t == 0){
				ans++;
				t = c;
				c = 0;
			}
		}
		return -1;
	}
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int ans = bfs(adj,V,X);
	    return ans;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends