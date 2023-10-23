class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0){
            return false;
        }
        if(ceil((long double)log2(n)) !=floor((long double)log2(n))){
            return false;
        }
        long long t = log2l(n);
        if(t&1)
            return false;
        return true;
    }
};