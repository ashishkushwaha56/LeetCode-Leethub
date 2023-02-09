//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> mb = {{'b',1},{'a',1},{'l',1},{'o',1},{'n',1}};
        vector<int> v(26);
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        int ans = s.size();
        for(int i = 0;i<26;i++){
            if(mb.find(i+'a')!=mb.end()){
                if(i+'a' == 'l' or i+'a' == 'o'){
                    ans = min(ans,v[i]/2);
                }
                else{
                    ans = min(ans,v[i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends