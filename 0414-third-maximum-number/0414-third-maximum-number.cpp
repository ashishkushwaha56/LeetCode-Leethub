class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> sd;
        for(auto &ot:nums){
            sd.insert(ot);
        }
        auto it = sd.end();
        int i = 0;
        it--;
        if(sd.size()<3) return *it;
        while(true){
            i++;
            if(i == 3) return *it;
            if(it == sd.end()) break;
            it--;
        }
        return 0;
    }
};