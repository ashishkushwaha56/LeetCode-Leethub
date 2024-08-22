class Solution {
public:
    int findComplement(int num) {
        string s = "";
        while(num>0){
            if(num&1) s+='1';
            else s+='0';
            num>>=1;
        }
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        long long j = 1;
        int ans = 0;

        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '0') ans+=j;
            j*=2;
        }
        return ans;
    }
};