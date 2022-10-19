//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,int i,int cnt){
        if(cnt==adj.size()) return true;
        vis[i] = 1;
        for(auto it:adj[i]){
            if(vis[it] == 0){
                if(dfs(adj,vis,it,cnt+1)){
                    return true;
                }
            }
        }
        vis[i] =0;
        return false;
    }
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        vector<vector<int>> adj(n);
        for(int i = 0;i<m;i++){
            adj[Edges[i][0]-1].push_back(Edges[i][1]-1);
            adj[Edges[i][1]-1].push_back(Edges[i][0]-1);
        }
        vector<int> vis(n);
        for(int i = 0;i<n;i++){
            if(dfs(adj,vis,i,1)){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends