//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int cnt=  0;
        int flag = 0;
        // if(m==1 and n !=0) return false;
        if(m == 1 and seats[0] == 0 and n == 1) return true;
        for(int i = 0;i<m;i++){
            if(seats[i] == 0){
                cnt++;
            }
            else{
                if(flag == 0){
                    if(cnt%2 ==0){
                        n-=min(n,cnt/2);
                    }
                    else{
                        n-=min(n,cnt/2);
                    }
                    flag = 1;
                }
                else{
                    if(cnt%2 == 1){
                        n-=min(n,cnt/2);
                    }
                    else{
                        n-=min(n,cnt/3);
                    }
                }
                cnt =0;
                
            }
            if(n == 0) return true;
        }
        if(flag == 0){
            if(cnt%2 ==0){
                        n-=min(n,cnt/2);
                    }
                    else{
                        n-=min(n,cnt/2);
                    }
        }
        else{
        if(cnt%2 ==0){
                        n-=min(n,cnt/2);
                    }
                    else{
                        n-=min(n,cnt/2);
                    }
        }
        // n-=min(n,cnt/3);
        return n==0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends