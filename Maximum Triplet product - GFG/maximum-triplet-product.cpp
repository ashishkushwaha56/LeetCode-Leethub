//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	vector<long long> pos,neg;
    	for(int i = 0;i<n;i++){
    		if(arr[i]>=0){
    			pos.push_back(arr[i]);
    		}
    		else{
    			neg.push_back(arr[i]);
    		}
    	}
    	sort(pos.begin(),pos.end());
    	sort(neg.begin(),neg.end());
    	if(neg.size() == 0){
    		return (pos[pos.size()-1]*pos[pos.size()-2]*pos[pos.size()-3]);
    	}
    	if(pos.size() == 0){
    		return (neg[neg.size()-1]*neg[neg.size()-2]*neg[neg.size()-3]);
    	}
    	else if(pos.size()==1){
    		return (neg[0]*neg[1]*pos[0]);
    	}
    	else if(pos.size() == 2 and neg.size()>=2){
    		return ((pos[1]*neg[0]*neg[1]));
    	}
    	else if(pos.size() == 2){
    		return (pos[0]*pos[1]*neg[neg.size()-1]);
    	}
    	else if(pos.size() >= 3){
    		return (max((neg[0]*neg[1]*pos[pos.size()-1]),pos[pos.size()-1]*pos[pos.size()-2]*pos[pos.size()-3]));
    	}
    	return 0;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends