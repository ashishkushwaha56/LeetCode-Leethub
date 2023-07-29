class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        while(a.size()<b.size()) a+='0';
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(b.size()<a.size()) b+='0';
        reverse(b.begin(),b.end());
        int carry = 0;
        int c;
        for(int i = a.size()-1;i>=0;i--){
            c = a[i]-'0';
            a[i] = (a[i]-'0'+b[i]-'0'+carry)%2+'0';
            carry = (carry+c+b[i]-'0')/2;
        }
        if(carry!=0){
            a = '1'+a;
        }
        return a;
    }
};