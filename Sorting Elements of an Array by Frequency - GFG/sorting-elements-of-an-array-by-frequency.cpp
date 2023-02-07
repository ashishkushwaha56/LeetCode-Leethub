//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int> mb;
        for(int i = 0;i<n;i++){
            mb[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto &it:mb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           if(a.second == b.second) return a.first<b.first;
           return a.second>b.second;
        });
        vector<int> ans;
        for(int i = 0;i<v.size();i++){
            while(v[i].second){
                ans.push_back(v[i].first);
                v[i].second--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends