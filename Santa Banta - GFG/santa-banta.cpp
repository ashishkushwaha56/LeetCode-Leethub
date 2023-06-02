//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> ans;
    vector<bool> is_prime;
    void precompute(){
        // vector<bool> is_prime(1000001,true);
        is_prime.resize(1000001,true);
        // cout<<1<<endl;
        for(int i = 2;i*i<=1000000;i++){
            if(is_prime[i]){
                for(int j = i*i;j<=1000000;j+=i){
                    is_prime[j] = false;
                    
                }
                ans.push_back(i);
            }
        }
        for(int j = sqrt(1000000)+1;j<=1000000;j++){
            if(is_prime[j]){
                ans.push_back(j);
            }
        }
        // for(auto &it:ans){
        //     cout<<it<<endl;
        // }
    }
    void dfs(vector<vector<int>>&v,vector<int>&vis,int &cnt,int i){
        vis[i] = 1;
        cnt++;
        for(auto &it:v[i]){
            if(!vis[it]){
                dfs(v,vis,cnt,it);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // vector<vector<int>>v(n+1);
        // // cout<<v.size();
        // int u,v1;
        // for(int i = 1;i<=m;i++){
        //     // u = g[i][0];
        //     // v1 = g[i][1];
            
        //     // cout<<u<<" "<<v1<<endl;
        //     cout<<g[i].size()<<endl;
        //     for(auto &it:g[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        //     // v[g[i][0]].push_back(g[i][1]);
        //     // v[g[i][1]].push_back(g[i][0]);
        // }
        // for(int i = 0;i<v.size();i++){
        //     for(auto &it:v[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(n+1);
        int maxd = 0;
        int cnt = 0;
        for(int i = 1;i<n+1;i++){
            cnt = 0;
            if(!vis[i])
                dfs(g,vis,cnt,i);
            maxd =max(maxd,cnt);
        }
        if(maxd>1)
            return ans[maxd-1];
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends