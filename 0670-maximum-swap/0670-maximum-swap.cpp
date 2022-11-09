class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string a =s;
        sort(a.rbegin(),a.rend());
        for(int i = 0;i<s.size()-1;i++){
            if(s[i] == a[i]){
                continue;
            }
            int l = -1;
            for(int j = s.size()-1;j>=i+1;j--){
                if(a[i] == s[j]){
                    l = j;
                    break;
                }
            }
            swap(s[l],s[i]);
            break;
        }
        return stoi(s);
    }
};