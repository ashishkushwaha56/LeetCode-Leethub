//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int cnt1 = 0;
	    int cnt2 = 0;
	    int ans = 0;
	    for(int i = 1;i<nums.size()-1;i++)
	    {
	        cnt1=0,cnt2 = 0;
	        for(int j = 0;j<i;++j){
	            if(nums[j]<nums[i]) cnt1++;
	        }
	        for(int j = i+1;j<nums.size();++j){
	            if(nums[j]>nums[i]) cnt2++;
	        }
	        ans+=(cnt1*cnt2);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends