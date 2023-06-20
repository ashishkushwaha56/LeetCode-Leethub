class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        // string a,b;
        vector<int> v;
        for(int i = 0;i<operations.size();i++){
            if(operations[i] == "C"){
                v.pop_back();
            }
            else if(operations[i] == "D"){
                int a = v.back();
                v.push_back(2*a);
            }
            else if(operations[i] == "+"){
                int a = v.back();
                int b = v[v.size()-2];
                v.push_back(a+b);
            }
            else{
                v.push_back(stoi(operations[i]));
            }
        }
        return accumulate(v.begin(),v.end(),0ll);
    }
};