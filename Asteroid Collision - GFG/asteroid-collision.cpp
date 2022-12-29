//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        stack<int> s;
        for(int i=0;i<N;i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else{
                if(arr[i]<0){
                    if(s.top()>0){
                        if(s.top()<abs(arr[i])){
                            while(!s.empty() and s.top()>0 and s.top()<abs(arr[i])){
                                s.pop();
                            }
                            if(!s.empty() and s.top()>0 and s.top() == abs(arr[i])){
                                s.pop();
                            }
                            else if(!s.empty() and s.top()>0 and s.top()>abs(arr[i]))
                                continue;
                            else
                                s.push(arr[i]);
                        }
                        else if(s.top() == abs(arr[i])){
                            s.pop();
                        }
                    }
                    else{
                        s.push(arr[i]);
                    }
                }
                else{
                    s.push(arr[i]);
                }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends