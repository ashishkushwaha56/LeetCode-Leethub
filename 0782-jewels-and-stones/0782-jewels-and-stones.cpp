class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        set<char> sd;
        for(auto &it:jewels){
            sd.insert(it);
        }
        for(auto &it:stones){
            if(sd.find(it)!=sd.end()) cnt++;
        }
        return cnt;
    }
};