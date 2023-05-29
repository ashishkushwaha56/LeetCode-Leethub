class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 or k%5 == 0) return -1;
        int cnt = 0;
        for(int i = 1;i<k+1;i++){
            cnt = (cnt*10+1)%k;
            if(cnt == 0) return i;
        }
        return -1;
    }
};