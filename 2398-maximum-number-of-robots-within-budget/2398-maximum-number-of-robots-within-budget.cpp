class Solution {
public:
    int maximumRobots(vector<int>& time, vector<int>& cost, long long budget) {
        int n = time.size();
        vector<long long> pre(n+1);
        pre[1] = cost[0];
        for(int i = 1;i<n;i++){
            pre[i+1] = pre[i]+cost[i];
        }
        map<int,int> mb;
        int l = 0;
        int ans = 0;
        long long curr = 0;
        // for(int i = 0;i<n+1;i++){
        //     cout<<pre[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0;i<n;i++){
            mb[time[i]]++;
            auto it = mb.end();
            it--;
            curr = ((*it).first+(i-l+1)*(pre[i+1]-pre[l]));
            // cout<<curr<<" "<<(i-l+1)<<" "<<endl;
            
            if(curr<=budget){
                ans = max(ans,(i-l+1));
            }
            else{
                mb[time[l]]--;
                if(mb[time[l]] == 0){
                    mb.erase(time[l]);
                }
                l++;
            }
        }
        // cout<<endl;
        return ans;
    }
};