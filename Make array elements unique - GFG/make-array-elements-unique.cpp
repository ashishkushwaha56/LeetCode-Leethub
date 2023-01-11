//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        long long ans = 0;
        map<int,int> mb;
        for(int i = 0;i<N;i++){
            mb[arr[i]]++;
        }
        auto it = mb.begin();
        while(it!=mb.end()){
            if((*it).second==1){
                it++;
            }
            else{
                ans++;
                mb[(*it).first]--;
                mb[(*it).first+1]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends