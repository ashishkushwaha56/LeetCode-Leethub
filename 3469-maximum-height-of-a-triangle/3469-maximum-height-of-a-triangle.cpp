class Solution {
public:
    int f1(int n){
        int cnt = 0;
        int i = 1;
        while(n>0){
            n-=i;
            if(n>=0) cnt++;
            i+=2;
        }
        return cnt;
    }
    int f2(int n){
        int cnt = 0;
        int i = 2;
        while(n>0){
            n-=i;
            if(n>=0) cnt++;
            i+=2;
        }
        return cnt;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int a1 = f1(red);
        int a2 = f2(blue);
        int ans = 0;
        if(a1>a2){
            ans = a2*2+1;
        }
        else if(a2>=a1){
            ans = a1+a1;
        }
        int b1 = f1(blue);
        int b2 = f2(red);
        if(b1>b2){
            ans = max(b2*2+1,ans);
        }
        else if(b2>=b1){
            ans = max(ans,b1+b1);
        }
        return ans;
    }   
};