class Solution {
public:
    string largestPalindromic(string s) {
        vector<int> v(10);
        for(int i = 0;i<s.size();i++){
            v[s[i]-'0']++;
        }
        string a = "";
        for(int i = 9;i>=0;i--){
            for(int j = 0;j<v[i]/2;j++){
                a+=(i+'0');
            }
            v[i]%=2;
        }
        if(!a.empty() and a[0] == '0'){
            a.clear();
        }
        int flag = 0;
        char c;
        for(int i = 9;i>=0;i--){
            if(v[i] == 1){
                flag = 1;
                c = i+'0';
                break;
            }
        }
        int cnt = count(s.begin(),s.end(),'0');
        string b = a;
        reverse(b.begin(),b.end());
        
        if(cnt == s.size()){
            return "0";
        }
        if(flag){
            return a+c+b;
        }
        return a+b;
    }
};