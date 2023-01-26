//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	string caseSort(string& s,int n) {
		string a = "";
		string b = "";
		vector<bool> v(s.size(),false);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' and s[i] <= 'z') {
				a += s[i];
				v[i] = true;
			}
			else {
				b += s[i];
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int i = 0;
		int j = 0;
		string ans = "";
		for (int k = 0; k < s.size(); k++) {
			if (v[k]) {
				if (i < a.size()) {
					ans += a[i];
					i++;
				}
			}
			else {
				if (j < b.size()) {
					ans += b[j];
					j++;
				}
			}
		}
		return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends