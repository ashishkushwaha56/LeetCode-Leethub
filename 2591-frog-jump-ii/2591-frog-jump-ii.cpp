class Solution {
public:
    bool check(vector<int>&v,long long mid,vector<bool>&possible){
        int l = 0;
        // int last = 0;
        while(l<v.size()-1){
            long long next = v[l]+mid;
            int last = -1;
            while(l<v.size() and v[l]<=next){
                if(possible[l]){
                    last = l;
                }
                l++;
            }
            
            if(last==-1) return false;
            // cout<<last<<endl;
            possible[last] = false;
            // if(i>0)
            // possible[l-1] = false;
            
            l = last;
        }
        l = v.size()-1;
        // for(int i = 0;i<possible.size();i++){
        //     cout<<possible[i]<<" ";
        // }
        // cout<<endl;
        while(l>0){
            long long next = v[l]-mid;
            int last = -1;
            int j = l;
            while(l>=0 and v[l]>=next){
                // if(l==0) return true;
                if(possible[l]){
                    last = l;
                }
                l--;
                
            }
            // cout<<j<<endl;
            // cout<<last<<endl;
            if(l == -1 and last!=-1 ) return true;
            if(l == -1 and last == -1 and v[j]<=mid) return true;
            if(last==-1) return false;
            possible[last] = false;
            if(l==-1)break;
            // if(l<v.size()-1)
            // possible[l+1] = false;
            l = last;
        }
        return true;
    }
    int maxJump(vector<int>& stones) {
        if(stones.size() == 2) return stones[1];
        vector<bool> possible(stones.size(),true);
        long long l = 0;
        
        long long r = INT_MAX;
        long long ans = r;
        while(l<=r){
            long long mid = l+(r-l)/2;
            for(int i = 0;i<possible.size();i++){
                possible[i] = true;
            }
            if(check(stones,mid,possible)){
                // cout<<mid<<endl;
                // cout<<"---------"<<endl;
                ans =mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};