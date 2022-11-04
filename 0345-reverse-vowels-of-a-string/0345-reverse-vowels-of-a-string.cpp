class Solution
{
public:
    string reverseVowels(string &s)
    {
        unordered_set<char> vb = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char> temp;
        for(auto &it:s){
            if(vb.find(it)!=vb.end()){
                temp.push_back(it);
            }
        }
        int i = temp.size()-1;
        for(int j = 0;j<s.size();j++){
            if(vb.find(s[j])!=vb.end()){
                s[j] = temp[i];
                i--;
            }
        }
        return s;
    }
};