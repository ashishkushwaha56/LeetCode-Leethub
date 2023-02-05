class Solution {
public:
    int change(string s, int h){
        string a(s.begin(),s.end());
        string b;
        for(int i = 0;i<s.size();i++){
            if(s[i] == s[h]){
                a[i] = '9';
            }
        }
        
        // int h1 = stoi(a);
        int h1 = 0;
        for(int i = 0;i<s.size();i++){
            h1 = h1*10+(a[i]-'0');
        }
        // cout<<a<<endl;
        int c = 0;
        int ans = 0;
        int h2 = 0;
        for(int i = 0;i<s.size();i++){
            h2 = 0;
            c = i;
            b = string(s.begin(),s.end());
            for(int j = 0;j<s.size();j++){
                if(s[j] == s[c]){
                    b[j] = '0';
                }
            }
            for(int j = 0;j<s.size();j++){
                h2 = h2*10+(b[j]-'0');
            }
            if(h2==0 or b[0] == '0'){
                h2 = 0;
                for(int j = 0;j<s.size();j++){
                    if(s[j] == s[c]){
                        b[j] = '1';
                    }
                }
                for(int j = 0;j<s.size();j++){
                    h2 = h2*10+(b[j]-'0');
                }
                // h2 = stoi(b);
            }
            // cout<<b<<endl;
            ans = max(h1-h2,ans);
        }
        
        // int h2 =stoi(b);
        // int h2 = 0;
        
        
        return ans;
        
    }
    int maxDiff(int num) {
       string s = to_string(num);
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            ans = max(ans,change(s,i));
        }
        return ans;
    }
};