class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> ans={a,b,c};
        sort(ans.begin(),ans.end());
        int cnt = 0;
        int s = 0;
        while(ans[1]>0 and ans[2]>0){
            ans[1]--;
            ans[2]--;
            s = ans[0]+ans[1]+ans[2];
            ans[0]=*min_element(ans.begin(),ans.end());
            ans[2] = *max_element(ans.begin(),ans.end());
            ans[1] = s-(ans[0]+ans[2]);
            cnt++;
        }
        return cnt;
    }
};