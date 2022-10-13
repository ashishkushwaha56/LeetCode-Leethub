class Solution {
public:
    int addRungs(vector<int>& v, int dist) {
        int ans = 0;
        if(v[0]>dist){
            if(dist == 1){
                ans+=v[0]-1;
            }
            else
                 ans+=(v[0]-dist)/dist;
                    if((v[0]-dist)%dist>0){
                        ans++;
                    }
        }
        for(int i = 1;i<v.size();i++){
            if(v[i]-v[i-1]>dist){
                if(dist == 1){
                    ans+=(v[i]-v[i-1]-1);
                }
                else{
                    ans+=(v[i]-v[i-1]-dist)/dist;
                    if((v[i]-v[i-1]-dist)%dist>0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};