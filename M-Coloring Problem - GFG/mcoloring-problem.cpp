//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool safe(bool graph[101][101],vector<int>&color,int n,int node,int d){
        for(int i= 0;i<n;i++){
            if(graph[node][i] == 1 and color[i] == d) return false;
        }
        return true;
    }
    bool check(bool graph[101][101],vector<int>&color,int n, int m,int node){
        if(node == n) return true;
        for(int i =1;i<=m;i++){
            if(safe(graph,color,n,node,i)){
                color[node] = i;
                if(check(graph,color,n,m,node+1)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
         vector<int> color(n);
         return check(graph,color,n,m,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends