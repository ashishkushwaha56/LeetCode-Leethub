//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    stack<char> sd;
    for(int i = 0;i<s.size();i++){
        if(sd.empty()){
            sd.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(sd.top() == '('){
                    sd.pop();
                }
                else{
                    sd.push(s[i]);
                }
            }
            else if(s[i]==']'){
                if(sd.top() == '['){
                    sd.pop();
                }
                else{
                    sd.push(s[i]);
                }
            }
            else if(s[i]=='}'){
                if(sd.top() == '{'){
                    sd.pop();
                }
                else{
                    sd.push(s[i]);
                }
            }
            else{
                sd.push(s[i]);
            }
        }
    }
    return (sd.size()==0);
}