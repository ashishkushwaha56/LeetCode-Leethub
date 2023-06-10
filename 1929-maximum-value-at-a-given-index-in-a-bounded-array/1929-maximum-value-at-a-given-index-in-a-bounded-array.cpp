class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1;
        int r = maxSum;
        int ans = l;
        long long m = maxSum;
        bool ok = false;
        while(l<=r){
            int mid = l+(r-l)/2;
            int minside = min(index,n-1-index);
            int maxside = max(index,n-1-index);
            m = maxSum-mid;
            ok = true;
            if(m<0) ok = false;
            long long required_dis = mid-1;
            // cout<<mid<<endl;
            
            if(minside>required_dis){
                m-=(required_dis*(required_dis+1))/2+(minside-required_dis);
                if(m<0) ok = false;
                // ok =false;
            }
            else{
                long long remain_dis = required_dis-minside;
                m-=(((required_dis*(required_dis+1))/2)-(remain_dis*(remain_dis+1))/2);
                if(m<0) ok=false;
            }

            if(maxside>=required_dis){
                m-=(required_dis*(required_dis+1))/2+maxside-required_dis;
                if(m<0) ok = false;
                // ok = false;
            }
            else{
                long long remain_dis = required_dis-maxside;
                // cout<<((required_dis*(required_dis+1))/2)<<endl;
                // cout<<(remain_dis*(remain_dis+1))/2<<endl;
                m-=(((required_dis*(required_dis+1))/2)-(remain_dis*(remain_dis+1))/2);
                if(m<0) ok=false;
            }
            // cout<<(ok?"true":"false")<<endl;
            if(ok){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
            // cout<<"=-------"<<endl;
        }
        return ans;
    }
};