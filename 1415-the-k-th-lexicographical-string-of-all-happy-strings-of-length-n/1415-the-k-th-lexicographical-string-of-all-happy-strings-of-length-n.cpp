class Solution {
public:
    set<string> ans;
    void f(string &a,int n){
        if(n == 0){
            ans.insert(a);
            return;
        }
        // cout<<a<<endl;
        if(a.back() == 'a'){
            a+='b';
            f(a,n-1);
            a.pop_back();
            a+='c';
            f(a,n-1);
            a.pop_back();
        }
        else if(a.back()=='b'){
            a+='a';
            f(a,n-1);
            a.pop_back();
            a+='c';
            f(a,n-1);
            a.pop_back();
        }
        else{
            a+='a';
            f(a,n-1);
            a.pop_back();
            a+='b';
            f(a,n-1);
            a.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string a= "";
        for(int i = 0;i<3;i++){
            a+=(i+'a');
            f(a,n-1);
            a.pop_back();
        }
        if(k>ans.size()) return "";
        k--;
        set<string>::iterator it = ans.begin();
        while(k--){
            it++;
        }
        return (*it);
    }
};