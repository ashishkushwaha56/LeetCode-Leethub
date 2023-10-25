class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int a = kthGrammar(n-1,(k+1)/2);
        if(a == 0){
            if(k&1) return 0;
            return 1;
        }
        else {
            if(k&1) return 1;
            return 0;  
        }
    }
};