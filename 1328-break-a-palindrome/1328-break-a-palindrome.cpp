class Solution {
public:
    bool check (string &a){
        int i = 0;
        int j = a.size()-1;
        while(i<=j){
            if(a[i]!=a[j]){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
}
    string breakPalindrome(string &p) {
        map<string,int> mb;
        // mb[p]++;
        int i = 0;
        int j = p.size()-1;
        char a,b;
        while(i<=j){
            a = p[i];
            for(int k = 0;k<26;k++){
                p[i] = k+'a';
                if(!check(p)){
                    mb[p]++;
                    break;
                }
            }
            // cout<<p<<endl;
            // if(!s.empty())
            //     cout<<s.top()<<endl;
            // while(!s.empty() and check(s.top(),p)){
            //     s.pop();
            // }
            // s.push(p);
            // if(!s.empty())
            //     cout<<s.top()<<endl;
            // if(!check(p))
            //     mb[p]++;
            p[i] = a;
            if(i == j) {
                break;
            }
            b = p[j];
            for(int k = 0;k<26;k++){
                p[j] = k+'a';
                if(!check(p)){
                    mb[p]++;
                    break;
                }
            }
            // if(p[j] == 'a'){
            //     p[j] =  'b';
            // }
            // else{
            //    p[j] = ('a'); 
            // }
            // cout<<p<<endl;
            // if(!s.empty())
            //     cout<<s.top()<<endl;
            // while(!s.empty() and check(s.top(),p)){
            //     s.pop();
            // }
            // s.push(p);
            // if(!s.empty())
            //     cout<<s.top()<<endl;
            // if(!check(p))
            //     mb[p]++;
            p[j] = b;
            i++;
            j--;
        }
        auto it=mb.begin();
        if(p.size() == 1){
            return "";
        }
        if((*it).first == p){
            return "";
        }
        return (*it).first;
    }
};