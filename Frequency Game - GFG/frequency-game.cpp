//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mb;
        for(int i = 0;i<n;i++){
            mb[arr[i]]++;
        }
        int cnt = INT_MAX;
        int dd = -1;
        for(auto &it:mb){
            if(it.second == cnt){
                if(dd<it.first){
                    dd = it.first;
                }
            }
            else if(it.second<cnt){
                cnt=it.second;
                dd = it.first;
            }
        }
        return dd;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends