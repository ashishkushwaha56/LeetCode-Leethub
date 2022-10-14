class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = string(n,'.');
        int i = n-1;
        while(i>=0){
            if(k-(n-1)>=26){
                s[i] = 'z';
                k-=26;
                n--;
            }
            else{
                s[i] = ((k-(n-1)-1)+'a');
                k-= (k-(n-1));
                n--;
            }
            i--;
        }
        return s;
    }
};