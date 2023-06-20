class Solution {
public:
    bool judgeCircle(string moves) {
        int a = 0,b = 0;
        for(auto &it:moves){
            if(it=='U') a++;
            else if(it=='D') a--;
            
            if(it == 'L')b++;
            else if(it == 'R')b--;
        }
        return a==0 and b == 0;
    }
};