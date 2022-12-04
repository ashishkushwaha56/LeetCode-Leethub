class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> pre(nums.size()+1);
        for(int i = 0;i<nums.size();i++){
            pre[i+1] = pre[i]+nums[i];
        }
        int ans = INT_MAX;
        long long c = INT_MAX;
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        vector<pair<int,long long>> vb;
        for(int i = 0;i<nums.size();i++){
            if(nums.size()-1-i == 0){
                if((pre[i+1]/(i+1))<c){
                    vb.push_back({i,c});
                    c =(pre[i+1]/(i+1));
                }
            }   
            else{
                if(abs((int)(pre[i+1]/(i+1))-(int)((sum-pre[i+1])/(nums.size()-1-i)))<c){
                    vb.push_back({i,c});
                    c = abs((int)(pre[i+1]/(i+1))-(int)((sum-pre[i+1])/(nums.size()-1-i)));
                }
            }
        }
        sort(vb.begin(),vb.end(),[&](pair<int,long long>&a,pair<int,long long>&b){
           if(a.second == b.second) return a.first<b.first;
            return a.second<b.second;
        });
        return vb[0].first;
    }
};