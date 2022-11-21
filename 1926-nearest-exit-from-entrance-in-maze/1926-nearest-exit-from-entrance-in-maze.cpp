class Solution {
public:
    int ans = 0;
    bool ok = false;
    void bfs(vector<vector<char>> &v,vector<int>& ent){
        queue<pair<int,int>> q;
        q.push({ent[0],ent[1]});
        pair<int,int> temp;
        int t = 1;
        int c = 0;
        
        v[ent[0]][ent[1]] = '+';
        while(!q.empty()){
            temp = q.front();
            q.pop();
            t--;
            // cout<<temp.first<<" "<<temp.second<<endl;
            if((temp.first == 0 or temp.first == v.size()-1 or temp.second == v[0].size()-1 or temp.second == 0) and (temp.first!=ent[0] or temp.second!=ent[1])){
                ok = true;
                break;
            }
            if(temp.first+1<v.size() and v[temp.first+1][temp.second]=='.'){
                v[temp.first+1][temp.second] = '+';
                q.push({temp.first+1,temp.second});
                c++;
            }
            if(temp.first-1>-1 and v[temp.first-1][temp.second]=='.'){
                v[temp.first-1][temp.second] = '+';
                q.push({temp.first-1,temp.second});
                c++;
            }
            if(temp.second+1<v[0].size() and v[temp.first][temp.second+1]=='.'){
                v[temp.first][temp.second+1] = '+';
                q.push({temp.first,temp.second+1});
                c++;
            }
            if(temp.second-1>-1 and v[temp.first][temp.second-1]=='.'){
                v[temp.first][temp.second-1] = '+';
                q.push({temp.first,temp.second-1});
                c++;
            }
            if(t == 0){
                t = c;
                if(c!=0) ans++;
                c = 0;
                
            }
        }
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {    
        bfs(maze,entrance);
        if(ans == 0 or !ok){
            return -1;
        }
        return ans;
    }
};