class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int> &v,vector<int>&gg,int i,int k){
        if(i == v.size()) {
            ans=min(ans,*max_element(gg.begin(),gg.end()));
            return;
        }
        for(int d = 0;d<k;d++){
            gg[d]+=v[i];
            helper(v,gg,i+1,k);
            gg[d]-=v[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>gg(k);
        helper(cookies,gg,0,k);
        return ans;
    }
};