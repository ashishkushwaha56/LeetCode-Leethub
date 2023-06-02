class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> v;
        int d = count(customers.begin(),customers.end(),'Y');
        int c = 0;
        for(int i = 0;i<customers.size();i++){
            v.push_back(c+d);
            if(customers[i] == 'N') c++;
            else d--;
        }
        v.push_back(d+c);
        int id = v.size()-1;
        int mind = v[v.size()-1];
        for(int i = v.size()-1;i>=0;i--){
            if(v[i]<=mind){
                mind = v[i];
                id = i;
            }
        }
        return id;
    }
};