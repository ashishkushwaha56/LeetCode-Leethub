class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int l = 0;
        int r = arr.size()-1;
        while(r-l+1>k){
            if(abs(arr[l]-x)<=abs(arr[r]-x))
            {
                r--;
            }
            else{
                l++;
            }
        }
        for(int i = l;i<=r;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};