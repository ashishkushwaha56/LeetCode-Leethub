class Solution {
public:
    
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        int i = 0;
        int j = 1;
        int k = 1;
        int cnt;
        for(int h = 2;h<n;h++){
            cnt = i+j+k;
            i = j;
            j = k;
            k = cnt;
        }
        return k;
    }
};