class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int right = count(moves.begin(),moves.end(),'R');
        int left = count(moves.begin(),moves.end(),'L');
        int ans = 0;
        if(right == left){
            string s = moves;
            for(auto &it:s){
                if(it == '_'){
                    it = 'R';
                }
            }
            int cnt = 0,a = 0;
            for(auto &it:s){
                if(it == 'R') {
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            // cout<<ans<<endl;
            // cout<<s<<endl;
            ans = max(ans,abs(cnt));
            s = moves;
            for(auto &it:s){
                if(it == '_'){
                    it = 'L';
                }
            }
            cnt = 0;
            a = 0;
            for(auto &it:s){
                if(it == 'R') {
                    cnt++;
                    
                }
                else{
                    cnt--;
                }
            }
            ans = max(ans,abs(cnt));
            // cout<<ans<<endl;
            // cout<<s<<endl;
        }
        else if(right>left){
            string s = moves;
            for(auto &it:s){
                if(it == '_'){
                    it = 'R';
                }
            }
            int cnt = 0,a = 0;
            for(auto &it:s){
                if(it == 'R') {
                    cnt++;
                   
                }
                else{
                   cnt--;
                }
               
            }
            ans = max(ans,abs(cnt));
        }
        else{
            string s = moves;
            for(auto &it:s){
                if(it == '_'){
                    it = 'L';
                }
            }
            int cnt = 0,a = 0;
            for(auto &it:s){
                if(it == 'R') {
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            ans = max(ans,abs(cnt));
        }
        return ans;
    }
};