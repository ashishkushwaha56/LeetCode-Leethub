class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0,b=0;
        int c = 0,d = 0;
        for(auto &it:colors){
            if(it == 'A'){
                if(d>2){
                    b+=(d-2);
                }
                d = 0;
                c++;
            }
            else{
                if(c>2){
                    a+=(c-2);
                }
                c = 0;
                d++;
            }
        }
        if(d>2){
            b+=(d-2);
        }
        if(c>2){
            a+=(c-2);
        }
        return a>b;
    }
};