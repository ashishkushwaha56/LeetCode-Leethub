class Solution {
public:
    int minFlips(int a, int b, int c) {
        string a1 = "";
        string b1 = "";
        string c1 = "";
        int i = 0;
        while(a){
            if(a&1) a1+='1';
            else a1+='0';
            a>>=1;
            i++;
        }
        while(i<31){
            a1+='0';
            i++;
        }
        i = 0;
        while(b){
            if(b&1) b1+='1';
            else b1+='0';
            b>>=1;
            i++;
        }
        while(i<31){
            b1+='0';
            i++;
        }
        i=0;
        while(c){
            if(c&1) c1+='1';
            else c1+='0';
            c>>=1;
            i++;
        }
        while(i<31){
            c1+='0';
            i++;
        }
        // cout<<a1<<endl;
        // cout<<b1<<endl;
        // cout<<c1<<endl;
        int ans = 0;
        for(i = 0;i<31;i++){
            if(c1[i] == '1'){
                if(a1[i] == '0' and b1[i] == '0') ans++;
            }
            else{
                ans+=((a1[i] == '1')?1:0);
                ans+=((b1[i] == '1')?1:0);
            }
        }
        return ans;
    }
};