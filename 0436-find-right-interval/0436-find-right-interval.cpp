class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<vector<int>,int>> p;
        for(int i = 0;i<intervals.size();i++){
            p.push_back({intervals[i],i});
        }
        sort(p.begin(),p.end());
        vector<int> ans(intervals.size(),-1);
        for(int i = 0;i<intervals.size();i++){
            pair<vector<int>,int> pd = {{intervals[i][1],intervals[i][1]},0};
            auto it = lower_bound(p.begin(),p.end(),pd)-p.begin();
            
            if(it < p.size()){
                // if(p[it].first == intervals[i]){
                //     it++;
                //     if(it<p.size()){
                //         ans[i] = p[it].second;
                //     }
                // }
                // else{
                    ans[i] = p[it].second;
            //     }
            }
        }
        return ans;
        
    }
};