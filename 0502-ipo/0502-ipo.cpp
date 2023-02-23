class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> temp(profits.size());
        for(int i = 0;i<temp.size();i++){
            temp[i].first = capital[i];
            temp[i].second = profits[i];
        }
        sort(temp.begin(),temp.end());
        priority_queue<int> p;
        int i = 0;
        while(k--){
            while(i<temp.size() and temp[i].first<=w){
                p.push(temp[i].second);
                i++;
            }
            if(p.empty()) return w;
            w+=p.top();
            p.pop();
        }
        return w;
    }
};