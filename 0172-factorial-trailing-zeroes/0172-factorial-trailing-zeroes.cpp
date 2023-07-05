class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int d = 5;
        int temp = n/d;
        while(temp>=1){
            ans+=temp;
            d*=5;
            temp = n/d;
        }
        return ans;
    }
};