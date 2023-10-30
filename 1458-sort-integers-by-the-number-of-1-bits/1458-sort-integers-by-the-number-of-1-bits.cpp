class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        int a,cnt;
        for(auto &it:arr){
            a = it;
            cnt = 0;
            while(a>0){
                cnt+=((a&1));
                a>>=1;
            }
            v.push_back({it,cnt});
        } 
        sort(v.begin(),v.end(),[&](pair<int,int>&b,pair<int,int>&c){
            if(b.second==c.second) return b.first<c.first;
            return b.second<c.second;
        });
        vector<int> ans;
        for(auto &it:v){
            ans.push_back(it.first);
        }
        return ans;
    }
};