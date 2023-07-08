class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> v;
        for(int i = 0; i < ratings.size(); i++){
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        int n = ratings.size(),x = 0, k= 0;
        vector<int> ans(n,0);
        for(auto &i: v){
            x = 0;
            if(i[1]-1>=0&&ratings[i[1]]>ratings[i[1]-1]){
                x = max(x,ans[i[1]-1]);
            }
            if(i[1]+1 < n&&ratings[i[1]]>ratings[i[1]+1]){
                x = max(x,ans[i[1]+1]);
            }
            ans[i[1]] = x+1;
            k += x+1;
        }
        return k;
    }
};