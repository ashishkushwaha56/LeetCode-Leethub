class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int cnt = 0;
        int d;
        for(int i = 0;i<n+1;i++){
            cnt = 0;
            d = i;
            while(d>0){
                if(d&1) cnt++;
                d>>=1; 
            }
            ans[i] = cnt;
        }
        return ans;
    }
};