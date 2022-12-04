//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        unordered_set<char> ss = {'a','e','i','o','u'};
       vector<int> mb(26),mc(26);
       int cnt1 = 0,cnt2=0;
       for(int i = 0;i<N;i++){
           if(ss.find(S[i])!=ss.end()){
               mb[S[i]-'a']++;
               cnt1++;
           }
           else{
               mc[S[i]-'a']++;
               cnt2++;
           }
       }
       if(abs(cnt1-cnt2)>1){
           return "-1";
       }
       int flag = 0;
       if(cnt1>cnt2){
           flag = 0;
       }
       else if(cnt2>cnt1){
           flag =1;
           
       }
       else{
           int i =0;
           int j = 0;
            while(i<26 and mb[i]==0){
                i++;
            }
            while(j<26 and mc[j] == 0){
                j++;
            }
           if(i<j){
               flag = 0;
           }
           else{
               flag = 1;
           }
       }
       string ans = "";
       int i = 0;
       int j = 0;
    //   for(auto &it: mb){
    //       cout<<it<<" ";
    //   }
    //   cout<<endl;
    //   for(auto &it:mc){
    //       cout<<it<<" ";
    //   }
    //   cout<<endl;
       while(i<26 and mb[i] == 0){
           i++;
       }
       while(j<26 and mc[j] == 0){
           j++;
       }
       while(i<26 or j<26){
           if(flag == 0){
               if(i<26){
                   ans+=(i+'a');
                   mb[i]--;
                   flag=1;
                   while(i<26 and mb[i]==0){
                       i++;
                   }
               }
               else{
                    break;
               }
           }
           else{
               if(j<26){
                   ans+=(j+'a');
                   mc[j]--;
                   while(j<26 and mc[j] == 0){
                       j++;
                   }
                   flag=0;
               }
               else{
                    break;
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends