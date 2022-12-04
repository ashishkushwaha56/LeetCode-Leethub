class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set2 = __builtin_popcountll(num2);
        int set1 = __builtin_popcountll(num1);
        string s1 = "";
        string s2 = "";
        while(num1){
            if(num1&1) s1+='1';
            else s1+='0';
            num1>>=1;
        }
        
        while(num2){
            if(num2&1) s2+='1';
            else s2+='0';
            num2>>=1;
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans;
        if(s1.size()<set2){
            ans = string(set2,'1');
        }
        else{
            bool ok = false;
            ans = "";
            for(int i = 0;i<s1.size();i++){
                if(ok){
                    set2--;
                    ans+='1';
                }
                else{
                    if(s1[i] == '1' and set2){
                        ans+='1';
                        set2--;
                    }
                    else{
                        ans+='0';
                    }
                }
                if(s1.size()-1-i == set2){
                    ok = true;
                }
            }
        }
        int c = 0;
        int i = 0;
        reverse(ans.begin(),ans.end());
        while(i<ans.size()){
            if(ans[i] == '1'){
                c+=(1ll<<i);
            }
            i++;
        }
        return c;
    }
};