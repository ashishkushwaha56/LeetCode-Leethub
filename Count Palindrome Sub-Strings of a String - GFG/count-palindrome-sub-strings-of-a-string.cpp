//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int check(char s[], int n, int i,int j){
    int ans = 0;
    while(i>=0 and j<n){
        if(s[i]!=s[j]){
            return ans;
        }
        if(j-i+1>=2) ans++;
        i--;
        j++;
    }
    // if(i<0){
    //     i++;
    // }
    // if(j==n){
    //     j--;
    // }
    // cout<<i<<" "<<j<<endl;
    // if(i<0) i++;
    // if(j==n) j--;
    // cout<<i+1<<" "<<j-1<<endl;
    if((j-1)-(i+1)<2) return ans;
    return ans;
}

int CountPS(char S[], int N)
{
    int ans = 0;
    for(int i = 1;i<N;i++){
        ans+=check(S,N,i-1,i);
        ans+=check(S,N,i,i);
    }
    return ans;
    
    
}