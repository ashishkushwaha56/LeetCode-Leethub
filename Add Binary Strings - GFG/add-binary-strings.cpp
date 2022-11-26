//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string &A, string &B)
	{
	    string a = "";
	    while(A.size()+a.size()<B.size()){
	        a+='0';
	    }
	    while(B.size()+a.size()<A.size()){
	        a+='0';
	    }
	    if(A.size()<B.size()){
	        A = a+A;
	    }
	    else{
	        B=a+B;
	    }
	    char c = '0';
	    string ans(A.size(),'.');
	    for(int i = A.size()-1;i>=0;i--){
	        if((A[i]-'0')+(B[i]-'0')+(c-'0') == 1){
	            ans[i] = '1';
	            c = '0';
	        }
	        else if((A[i]-'0')+(B[i]-'0')+(c-'0') == 0){
	            ans[i]='0';
	        }
	        else if((A[i]-'0')+(B[i]-'0')+(c-'0') == 2){
	            ans[i] = '0';
	            c = '1';
	        }
	        else if((A[i]-'0')+(B[i]-'0')+(c-'0') == 3){
	            ans[i] = '1';
	            c = '1';
	        }
	    }
	    if(c == '1'){
	        ans = '1'+ans;
	    }
	    reverse(ans.begin(),ans.end());
	    while(!ans.empty() and ans.back() == '0'){
	        ans.pop_back();
	    }
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends