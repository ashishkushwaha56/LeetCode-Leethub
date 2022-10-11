class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long> vb(61);
        for(int i = 0;i<time.size();i++){
            if(time[i] == 60){
                vb[60]++;
                continue;
            }
            vb[time[i]%60]++;
        }
        long long ans = 0;
        for(int i = 0;i<30;i++){
            ans+=vb[i]*vb[60-i];
        }
        ans+=(vb[30]*(vb[30]-1))/2;
        ans+=(vb[0]*(vb[0]-1))/2;
        ans+=(vb[60]*(vb[60]-1))/2;
        return ((int) ans);
    }
};