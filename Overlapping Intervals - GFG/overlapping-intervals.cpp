//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {
         sort(v.begin(),v.end());
         stack<vector<int>> s;
         vector<int> temp(2);
         for(int i = 0;i<v.size();i++){
             if(s.empty()){
                 s.push(v[i]);
             }
             else {
                 if(s.top()[1]>=v[i][0]){
                     temp[0] = s.top()[0];
                     temp[1] = max(v[i][1],s.top()[1]);
                     s.pop();
                     s.push(temp);
                 }
                 else{
                     s.push(v[i]);
                 }
             }
         }
         vector<vector<int>> ans;
         while(!s.empty()){
             ans.push_back(s.top());
             s.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends