class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int> mb,mc;

        for(int i = 0;i<bookings.size();i++){
            mb[bookings[i][0]-1]+=bookings[i][2];
            mc[bookings[i][1]-1]+=bookings[i][2];
        }
        vector<pair<int,int>> start,end;
        for(auto &it:mb){
            start.push_back({it.first,it.second});
        }
        for(auto &it:mc){
            end.push_back({it.first,it.second});
        }
        // for(int i = 0;i<start.size();i++){
        //     cout<<start[i].first<<" "<<start[i].second<<endl;
        // }
        // cout<<"-----------"<<endl;
        // for(int i = 0;i<end.size();i++){
        //     cout<<end[i].first<<" "<<end[i].second<<endl;
        // }
        int j = 0;
        int k = 0;
        int cnt =0;
        int i = 0;
        vector<int> ans(n);
        while(i<n){
            if(j<start.size() and start[j].first == i){
                cnt+=start[j].second;
                j++;
            }
            ans[i] = cnt;
            if(k<end.size() and end[k].first == i){
                cnt-=end[k].second;
                k++;
            }
            i++;
        }
        return ans;
    }
};