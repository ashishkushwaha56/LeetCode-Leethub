//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    void check(string &s,int i,int j, int n){
        if(j==n){
            ans.push_back(s);
            return;
        }
        if(i<n){
            s+='(';
            check(s,i+1,j,n);
            s.pop_back();
        }
        if(j<i){
            s+=')';
            check(s,i,j+1,n);
            s.pop_back();
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        string s = "";
        check(s,0,0,n);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends