//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


int minSteps(string str) {
    int a = 0,b = 0;
    int flag = str[0] == 'a';
    
    for(int i = 0;i<str.size();i++){
    	if(flag and str[i]!='a'){
    		a++;
    		flag = 0;
    	}
    	else if(!flag and str[i]!='b'){
    		b++;
    		flag = 1;
    	}
    }
    if(str[str.size()-1] == 'a') a++;
    else b++;
    return min(a,b)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends