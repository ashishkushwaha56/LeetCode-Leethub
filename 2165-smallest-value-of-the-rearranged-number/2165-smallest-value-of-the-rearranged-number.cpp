class Solution {
public:
    long long smallestNumber(long long num) {
        int a = 0;
        string b = "";
        string ans = "";
        string t = to_string(num);
        int flag = 0;
        if(num<0){
            flag = 1;
        }
        if(flag){
            for(int i = 1;i<t.size();i++){
                if(t[i] == '0') a++;
                else{
                    b+=t[i];
                }
                
            }
            sort(b.rbegin(),b.rend());
            for(int i = 0;i<b.size();i++){
                ans+=b[i];
            }
            for(int i = 0;i<a;i++){
                ans+='0';
            }
            return -(stol(ans));
        }
        else{
            for(int i = 0;i<t.size();i++){
                if(t[i] == '0'){
                    a++;
                }
                else{
                    b+=t[i];
                }
            }
            sort(b.begin(),b.end());
            if(!b.empty()){
                ans+=b[0];
            }
            for(int i = 0;i<a;i++){
                ans+='0';
            }
            for(int i = 1;i<b.size();i++){
                ans+=b[i];
            }
            return stol(ans);
        }
    }
};