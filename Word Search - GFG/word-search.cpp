//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    bool check(vector<vector<char>>&v,int i,int j,int k,string &word){
        if(k == word.size()-1) return true;
        char c = v[i][j];
        v[i][j] = '.';
        for(int h = 0;h<4;h++){
            if(i+dx[h]>=0 and i+dx[h]<v.size() and j+dy[h]>=0 and j+dy[h]<v[0].size()){
                if(v[i+dx[h]][j+dy[h]] == word[k+1]){
                    if(check(v,i+dx[h],j+dy[h],k+1,word)) return true;
                }
            }
        }
        v[i][j] = c;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(check(board,i,j,0,word)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends