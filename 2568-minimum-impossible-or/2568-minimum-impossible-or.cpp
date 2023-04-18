class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        for(int i =0;i<32;i++){
            if(mb.find(1<<i)==mb.end()) return (1<<i);
        }
        return (1<<32);
    }
};