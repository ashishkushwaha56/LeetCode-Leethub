class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int d =abs(num);
        while(d>0){
            ans+=(d%7)+'0';
            d/=7;
        }
        if(num<0) ans+='-';
        reverse(ans.begin(),ans.end());
        if(ans.size() == 0) ans+='0';
        return ans;
    }
};