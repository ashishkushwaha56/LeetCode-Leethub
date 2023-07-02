class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        for(int i = 0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        // cout<<v.size()<<endl;
        int l = 0;
        int ans = 0;
        int cnt = 0;
        sort(worker.begin(),worker.end());
        for(auto &it:worker){
            // l = 0;
            // cnt = 0;
            while(l<v.size() and it>=v[l].first){
                cnt=max(cnt,v[l].second);
                ++l;
            }
            ans+=cnt;
        }
        return ans;
    }
};