class Solution {
public:
    int distributeCandies(vector<int>& cd) {
        set<int> sd(cd.begin(),cd.end());
        return min(cd.size()/2,sd.size());
    }
};