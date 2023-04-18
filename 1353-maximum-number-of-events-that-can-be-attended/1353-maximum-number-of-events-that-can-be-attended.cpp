class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>, greater<int>> p;
        int ans = 0;
        sort(events.begin(),events.end());
        int i = 0;
        for(int d = 0;d<=100000;d++){
            while(!p.empty() and p.top()<d) p.pop();
            while(i<events.size() and events[i][0] ==d ){p.push(events[i][1]);i++;}
            if(!p.empty()) {p.pop(); ans++;}
            if(p.empty() and i == events.size()) break;
        }
        return ans;
    }
};