class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> sd;
        int k = 0;
        sd.insert(1);
        long long d = 1;
        while(k<n){
            d = *(sd.begin());
            sd.erase(d);
            k++;
            if(sd.find(2*d)==sd.end()) sd.insert(2*d);
            if(sd.find(3*d)==sd.end()) sd.insert(3*d);
            if(sd.find(5*d)==sd.end()) sd.insert(5*d);
            if(k==n) break;
        }
        return d;
    }
};