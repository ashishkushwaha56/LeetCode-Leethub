class Solution {
public:
    bool check(vector<int>&v,int m, int k, int mid){
        int cnt = 0;
        for(int i = 0;i<v.size();i++){
            if(m == 0) return true;
            // cout<<cnt<<" "<<m<<endl;
            if(v[i]<=mid){
                if(cnt == k){
                    cnt = 0;
                    m--;
                }
                cnt++;
            }
            else{
                if(cnt == k){
                    cnt = 0;
                    m--;
                }
                cnt = 0;
            }
        }
        if(m == 0) return true;
        if(cnt == k){
            m--;
        }
        if(m == 0) return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        int l = 1;
        int r = *max_element(v.begin(),v.end());
        int d = r;
        int ans=  1000000001;
        while(l<=r){
            int mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(check(v,m,k,mid)){
                cout<<1<<endl;
                if(mid<ans){
                    ans = mid;
                }
                r = mid-1;
                
            }
            else{
                l = mid+1;
            }
        }
        return (ans==1000000001?-1:ans);
    }
};