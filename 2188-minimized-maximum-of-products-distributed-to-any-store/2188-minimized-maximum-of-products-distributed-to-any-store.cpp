class Solution {
public:
    bool check(int n, vector<int>&v,int mid){
        int i = 0;
        int j = 0;
        while(i<n and j<v.size()){
            if(i+(v[j]/mid+(v[j]%mid!=0))>n) return false;
            i+=(v[j]/mid);
            i+=(v[j]%mid != 0);
            j++;
        }
        if(j<v.size()) return false;
        return true;
    }
    int minimizedMaximum(int n, vector<int>& v) {
        int l = 1;
        int r = 1e5+1;
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(n, v,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};