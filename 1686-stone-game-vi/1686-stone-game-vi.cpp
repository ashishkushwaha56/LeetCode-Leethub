class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        priority_queue<pair<int,int>> p;
        for(int i = 0;i<alice.size();i++){
            p.push({alice[i]+bob[i],alice[i]});
        }
        int flag = 0;
        int a=0,b=0;
        while(!p.empty()){
            if(!flag){
                a+=p.top().second;
                flag = 1;
                p.pop();
            }
            else{
                b+=p.top().first-p.top().second;
                flag = 0;
                p.pop();
            }
        }
        return ((a==b)?0:((a>b)?1:-1));
    }
};