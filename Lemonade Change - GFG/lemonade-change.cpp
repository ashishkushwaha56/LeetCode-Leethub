//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int a = 0;int b = 0;
        for(int i = 0;i<N;i++){
            if(bills[i] == 20){
                if(b>=1 and a>=1) {
                    a--;
                    b--;
                }
                else if(a>=3) a-=3;
                else {return false;}
            }
            else if(bills[i]==10){
                if(a>=1) a--;
                else {return false;}
                b++;
            }
            else a++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends