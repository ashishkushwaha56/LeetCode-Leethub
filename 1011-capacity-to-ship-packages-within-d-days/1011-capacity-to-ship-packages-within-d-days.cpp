class Solution {
public:
    bool check(vector<int> &v,int d,int t){
        int i = 0;
        int cnt = 0;
        while(i<v.size()){
            if(v[i]>t) return false;
            if(d==0) return false;
            cnt+=v[i];
            if(cnt>t){
                cnt-=(cnt-v[i]);
                d--;
            }
            else if(cnt==t){
                cnt=0;
                d--;
            }
            i++;
        }
        if(cnt!=0 and d==0) return false;
        // cout<<t<<endl;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int l = 1;
        int r = INT_MAX;
        int ans=r;
        while(l<=r){
            int mid = l+(r-l)/2;
            // cout<<l<<" "<<r<<endl;
            if(check(weights,days,mid)){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};