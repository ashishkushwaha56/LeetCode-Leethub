//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool check(string &s){
        int i = 0,l = s.size()-1;
        while(i<l){
            if(s[i]!=s[l]) return false;
            i++;
            l--;
        }
        return true;
    }
    bool makePalindrome(int n,vector<string> &arr){
        int flag = 0;
        map<string,int> mb;
        string temp = "";
        for(auto &it:arr){
            mb[it]++;
        }
        int a= 0;
        string s;
        while(true){
            auto it = mb.begin();
            if(it == mb.end()) break;
            temp = (*it).first;
            s = temp;
            reverse(temp.begin(),temp.end());
            if(s==temp) {
                if(flag == 0){
                    flag = 1;
                    mb.erase(s);
                }
                else return false;
                continue;
            } 
            if(mb.find(temp) == mb.end()){
                return false;
            }
            else{
                 a = min(mb[s],mb[temp]);
                mb[s]-=a;
                mb[temp]-=a;
                if(mb[s] == 0) mb.erase(s);
                if(mb[temp] == 0) mb.erase(temp);
            }
           
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends