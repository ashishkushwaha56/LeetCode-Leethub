class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        for(int i = 0;i<ranges.size();i++){

                v.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});

        }
        sort(v.begin(),v.end());

        vector<long long> dp(10010,-1);
        function<long long(int)> helper = [&](int i)->long long{
            
            if(v[i].second >= n) return 1;
            if(i==v.size()) return INT_MAX;
            if(dp[i]!=-1) return dp[i];
            long long ans = INT_MAX;
            for(int j = i+1;j<v.size();j++){
                if(v[j].first>v[i].second) break;
                ans = min(ans,1+helper(j));
            }
            return dp[i] = ans;
        };
        long long d = INT_MAX;
        for(int i= 0;i<v.size();i++){
            if(v[i].first == 0){
                d = min(d,helper(i));
            }
        }
        if(d==INT_MAX) return -1;
        return d;
    }
};