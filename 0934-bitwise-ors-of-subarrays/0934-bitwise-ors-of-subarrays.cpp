class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res,a,b;
        for(auto &it:arr){
            a = {it};
            for(auto &i:b) a.insert(it|i);
            for(auto &j:a) res.insert(j);
            b = a;
        }
        return res.size();
    }
};