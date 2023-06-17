class Solution {
public:
    int smallestEvenMultiple(int n) {
        return ((__gcd(2,n)==1?(2*n):n));
    }
};