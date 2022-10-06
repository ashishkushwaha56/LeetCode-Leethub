class Solution {
public:
    string largestMultipleOfThree(vector<int>& vb) {
        string ans = "";
        int sum = accumulate(vb.begin(),vb.end(),0ll);
        vector<int> v1,v2,v3;
        for(auto &it:vb){
            if(it%3 == 0)
                v3.push_back(it);
            else if(it%3 == 1)
                v2.push_back(it);
            else 
                v1.push_back(it);
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        sort(v3.rbegin(),v3.rend());
        if(sum%3 == 1){
            if(!v2.size()){
                if(v1.size()<2){
                    return ans;
                }
                else{
                    v1.pop_back();
                    v1.pop_back();
                }
            }
            else
                v2.pop_back();
        }
        else if(sum%3 == 2){
            if(!v1.size()){
                if(v2.size()<2){
                    return ans;
                }
                else{
                    v2.pop_back();
                    v2.pop_back();
                }
            }
            else
                v1.pop_back();
        }
        for(auto &it: v1){
            ans+=(it+'0');
        }
        for(auto &it: v2){
            ans+=(it+'0');
        }
        for(auto &it: v3){
            ans+=(it+'0');
        }
        sort(ans.rbegin(),ans.rend());
        if(!ans.empty() and ans[0] == '0'){
            return "0";
        } 
        return ans;
    }
};