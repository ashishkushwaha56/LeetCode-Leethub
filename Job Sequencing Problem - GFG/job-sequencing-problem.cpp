//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxslot = 0;
        for(int i = 0;i<n;i++){
            maxslot = max(arr[i].dead,maxslot);
        }
        set<int> sd;
        for(int i = 1;i<=maxslot;i++){
            sd.insert(i);
        }
        sort(arr,arr+n,[&](Job &a,Job&b){
           return a.profit>b.profit; 
        });
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(sd.size()==0) break;
            auto it=sd.lower_bound(arr[i].dead);
            if(it == sd.end()){
                it--;
                cnt++;
                ans+=arr[i].profit;
                sd.erase(it);
            }
            else{
                if((*it) == arr[i].dead){
                //   vit--;
                    cnt++;
                    ans+=arr[i].profit;
                    sd.erase(it); 
                }
                else{
                    if(it == sd.begin()) continue;
                    it--;
                    cnt++;
                    ans+=arr[i].profit;
                    sd.erase(it);                    
                }
            }
        }
        return {cnt,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends