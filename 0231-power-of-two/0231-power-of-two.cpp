class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long d = n;
        if(d == 0 ) return false;
        return ((d&(d-1)) == 0);
    }
};