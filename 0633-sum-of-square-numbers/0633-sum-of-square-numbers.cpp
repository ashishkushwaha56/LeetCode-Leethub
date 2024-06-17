class Solution {
public:
    bool judgeSquareSum(int c) {
       for(int i = 0;i<=sqrt(c)+1;i++){
        long long d = c-(long long)i*i;
        if(d<0) continue;
        long long a = (long long)sqrt(d);
        if((long long)a*a==(long long)d){
            return true;
        }
       } 
       return false;
    }
};