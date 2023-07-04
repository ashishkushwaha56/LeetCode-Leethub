class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> sd;
        long long it = 1;
        sd.insert(it);
        for(int i = 0;i<n;i++){
            it = *(sd.begin());
            sd.erase(it);
            sd.insert(it*2);
            sd.insert(it*3);
            sd.insert(it*5);
        }
        return it;
    }
};