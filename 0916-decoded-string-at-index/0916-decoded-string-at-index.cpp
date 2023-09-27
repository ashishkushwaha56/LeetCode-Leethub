class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long cnt = 0;
        for(auto &it:s){
            if(isdigit(it)){
                cnt*=(it-'0');
            }
            else{
                cnt++;
            }
        }
        for(int i = s.size()-1;i>=0;i--){
            if(isdigit(s[i])){
                cnt /=(s[i]-'0');
                k = k%cnt;
            }
            else{
                if(k == 0 or cnt == k) return string("")+s[i];
                cnt--;
            }
        }
        return "";
    }
};