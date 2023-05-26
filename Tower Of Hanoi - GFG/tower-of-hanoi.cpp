//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void toh1(int n,char a,char c, char b){
        if(n ==0) return;
        toh1(n-1,a,b,c);
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
        toh1(n-1,b,c,a);
    }
    
    long long toh(int N, int from, int to, int aux) {
        long long ans = 1ll<<N;
        ans--;
        toh1(N,from+'0',to+'0',aux+'0');
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends