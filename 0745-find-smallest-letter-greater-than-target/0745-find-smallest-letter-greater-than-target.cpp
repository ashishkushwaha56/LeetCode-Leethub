class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> v;
        for(auto &it:letters){
            v.push_back(it-'a');
        }
        auto it=upper_bound(v.begin(),v.end(),target-'a');
        if(it == v.end()) return letters[0];
        return ((*it)+'a');
    }
};