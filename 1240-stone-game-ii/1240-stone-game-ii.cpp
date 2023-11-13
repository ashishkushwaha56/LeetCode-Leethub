class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        vector<int> pre(piles.size()+1);
        for(int i = 1;i<piles.size()+1;i++){
            pre[i] = pre[i-1]+piles[i-1];
        }
        // cout<<pre.back()<<endl;
        function<int(int ,int,int )> helper = [&](int i,int m,int aliceturn)->int{
            if(i>=piles.size()) return 0;
            if(dp[i][m][aliceturn]!=-1) return dp[i][m][aliceturn];
            // cout<<i<<" "<<aliceturn<<endl;
            if(aliceturn){
                int ans = 0;
                for(int x = 1;x<=2*m;x++){
                    if(i+x<piles.size()+1){
                        ans = max(ans,(pre[i+x]-pre[i])+helper(i+x,max(m,x),0));
                    }
                }
                return dp[i][m][aliceturn] = ans;
            }
            int ans = INT_MAX;
            for(int x = 1;x<=2*m;x++){
                if(i+x<piles.size()+1){
                    ans = min(ans,helper(i+x,max(m,x),1));
                }
                
            }
            return dp[i][m][aliceturn] = ans;
        };
        int alice = helper(0,1,1);
        return alice;


    }
};