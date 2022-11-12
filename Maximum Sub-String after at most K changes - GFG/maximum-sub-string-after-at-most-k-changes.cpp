//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int ans = 0;
		    int l = 0;
		    vector<int> temp(26);
		    for(int i = 0;i<s.size();i++){
		        temp[s[i]-'A']++;
		        if(i-l+1-*max_element(temp.begin(),temp.end())<=k){
		            ans = max(ans,i-l+1);
		        }
		        else{
		            temp[s[l]-'A']--;
		            l++;
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends