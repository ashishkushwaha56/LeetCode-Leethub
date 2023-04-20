class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(int i = 0;i<num.size();i++){
            if(s.empty()){
                s.push(num[i]-'0');
            }
            else{
                while(!s.empty() and s.top()>(num[i]-'0') and k>0){
                    s.pop();
                    k--;
                }
                s.push(num[i]-'0');
            }
        }
        while(k>0){
            s.pop();
            k--;
        }
        string ans = "";
        
        while(!s.empty()){
            ans+=(s.top()+'0');
            s.pop();
        }
        while(ans.size()>0 and ans.back() == '0'){
            ans.pop_back();
        }
        if(ans.size() == 0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};