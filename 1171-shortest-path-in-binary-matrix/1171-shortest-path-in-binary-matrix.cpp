class Solution {
public:
    bool ok=false;
    vector<int>dx = {0,0,1,-1,1,1,-1,-1};
    vector<int>dy = {1,-1,0,0,-1,1,1,-1};
    int bfs(vector<vector<int>>&v){
        queue<pair<int,int>> q;
        pair<int,int> temp;
        int t = 1;
        int c  =0;
        int ans = 0;
        q.push({0,0});

        if(v[0][0] == 1) {
            // ok = false;
            return -1;
        }
        v[0][0] = 1;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            // cout<<temp.first<<" "<<temp.second<<endl;
            if(temp.first == v.size()-1 and temp.second == v[0].size()-1){
                // if(v[v.size()-1][v[0].size()-1] == 1){
                //     // ok = false;
                //     return -1;
                // }
                ok = true;
                break;
            }
            t--;
            // cout<<temp.first<<" "<<temp.second<<endl;
            for(int i = 0;i<8;i++){
                if(temp.first+dx[i]>=0 and temp.first+dx[i]<v.size() and temp.second+dy[i]>=0 and temp.second+dy[i]<v[0].size()){
                    if(!v[temp.first+dx[i]][temp.second+dy[i]]){
                        v[temp.first+dx[i]][temp.second+dy[i]] = 1;
                        c++;
                        q.push({temp.first+dx[i],temp.second+dy[i]});

                    }
                }
            }
            if(t == 0){
                ans++;
                t = c;
                c= 0;
            }
        }
        if(!ok) return -1;
        return ans+1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       return bfs(grid);  
    }
};