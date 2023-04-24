//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int> ans(arr.size());
        stack<pair<int,pair<int,int>>> s;
        int d,e;
        for(int i = 0;i<arr.size();i++){
            if(s.empty()){
                s.push({arr[i],{i,-1}});
                ans[i] = -1;
            }
            else{
                if(s.top().first>arr[i]){
                    while(!s.empty() and s.top().first>arr[i]){
                        if(s.top().second.second>=0){
                            d = abs(s.top().second.second-s.top().second.first);
                            e = abs(s.top().second.first-i);
                            if(d>e){
                                ans[s.top().second.first] = i;
                            }
                            else if(d==e){
                                // ans[s.top().second.]
                                if(arr[s.top().second.second] > arr[i]){
                                    // ans[s.top().]
                                    ans[s.top().second.first] = i;
                                }
                                // else if(arr[s.top().second.second] == arr[i]){
                                    
                                // }
                                
                            }
                            
                        }
                        else{
                            break;
                        }
                        s.pop();
                    }
                    if(s.empty()){
                        ans[i] = -1;
                        s.push({arr[i],{i,-1}});
                    }
                    else{
                        if(s.top().first == arr[i]){
                            if(s.top().second.second == -1){
                                ans[i] = s.top().second.second;
                                s.push({arr[i],{i,-1}});
                            }
                            else{
                                ans[i] = s.top().second.second;
                                s.push({arr[i],{i,s.top().second.second}});
                            }
                        }
                        else if(s.top().first >arr[i]){
                            while(!s.empty() and s.top().first>arr[i]){
                                ans[s.top().second.first] = i;
                                // ans[i] = -1;
                                s.pop();
                                // s.push({arr[i],{i,-1}});
                            }
                            ans[i] = -1;
                            s.push({arr[i],{i,-1}});
                            
                        }
                        else{
                            ans[i] = s.top().second.first;
                            s.push({arr[i],{i,s.top().second.first}});
                        }
                    }
                }
                else{
                    if(s.top().first == arr[i]){
                            if(s.top().second.second == -1){
                                ans[i] = s.top().second.second;
                                s.push({arr[i],{i,-1}});
                            }
                            else{
                                ans[i] = s.top().second.second;
                                s.push({arr[i],{i,s.top().second.second}});
                            }
                    }
                    else{
                        ans[i] = s.top().second.first;
                        s.push({arr[i],{i,s.top().second.first}});
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends