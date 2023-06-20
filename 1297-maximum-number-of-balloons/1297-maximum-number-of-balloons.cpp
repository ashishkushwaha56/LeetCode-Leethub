class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0,b = 0,l = 0,o = 0,n = 0;
        for(auto &it:text){
            a+=(it == 'a');
            b+=(it == 'b');
            l+=(it =='l');
            o+=(it == 'o');
            n+=(it == 'n');
        }
        return min({a,b,l/2,o/2,n});
    }
};