class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mb;
        int cnt = 0;
        int i = 0;
        int d = 0;
        while(d!=1 and i<100000){
            while(n>0){
                cnt+=((n%10)*(n%10));
                n/=10;
            }
            if(mb.find(cnt)!=mb.end()) return false;
            mb[cnt]++;
            n = cnt;
            d = cnt;
            cnt=0;
            cout<<cnt<<endl;
            i++;
        }
        if(d!=1) return false;
        return true;
    }
};