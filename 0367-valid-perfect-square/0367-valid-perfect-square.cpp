class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(mid*mid == num) return true;
            else if(mid*mid<num){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};