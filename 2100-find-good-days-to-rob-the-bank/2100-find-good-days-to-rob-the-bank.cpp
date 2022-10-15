class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> pre(security.size()),suf(security.size());
        pre[0] = 1;
        int t = 1;
        for(int i = 1;i<security.size();i++){
            if(security[i-1]>=security[i]) t++;
            else t =1;
            pre[i] = t;
        }
        suf[security.size()-1] = 1;
        t = 1;
        vector<int> ans;
        if(time == 0){
            for(int i = 0;i<security.size();i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i = security.size()-2;i>=0;i--){
            if(security[i]<=security[i+1]) t++;
            else t = 1;
            suf[i] = t;
        }
        for(int i = 0;i<security.size();i++){
            if(pre[i]-1>=time and suf[i]-1>=time) ans.push_back(i);
        }
        return ans;
    }
};