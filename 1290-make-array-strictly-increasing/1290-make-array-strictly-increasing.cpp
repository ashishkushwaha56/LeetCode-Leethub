class Solution {
public:
    int helper(map<pair<int,int>,int> &dp,int prev,int i,vector<int>&arr1,vector<int>&arr2){
        if(i == arr1.size()) return 0;
        if(dp.find({prev,i})!=dp.end()) return dp[{prev,i}];
        auto id = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        int ans = INT_MAX/2;
        if(arr1[i]>prev) ans = min(ans,helper(dp,arr1[i],i+1,arr1,arr2));
        if(id<arr2.size()) ans = min(ans,helper(dp,arr2[id],i+1,arr1,arr2)+1);
        return dp[{prev,i}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> dp;
        int ans = helper(dp,INT_MIN,0,arr1,arr2);
        return ans>=INT_MAX/2?-1:ans;
    }
};