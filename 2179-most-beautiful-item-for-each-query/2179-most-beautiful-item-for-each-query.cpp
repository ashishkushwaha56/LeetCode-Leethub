class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> v(items.size());
        v[0] = items[0][1];
        for(int i = 1;i<v.size();i++){
            v[i] = max(v[i-1],items[i][1]);
        }
        vector<int> ans(queries.size());
        for(int i = 0;i<queries.size();i++){
            vector<int> p = {queries[i],INT_MAX};
            auto it = upper_bound(items.begin(),items.end(),p)-items.begin();
            // cout<<it<<endl;
            it--;
            if(it<0) continue;
            ans[i] = v[it];
        }
        return ans;
    }
};