class Solution {
public:
    
    string countAndSay(int n) {
        int  i = 1;
        string a = "1";
        if(n == 1) return a;
        // int j = 0;
        int count = 0;
        int num = 0;
        string temp;
        while(i<n){
            // j = 0;
            temp = "";
            num = a[0]-'0';
            count = 1;
            for(int j = 1;j<a.size();j++){
                if(a[j] == a[j-1]){
                    count++;
                }
                else{
                    // cout<<count<<" "<<num<<endl;
                    temp+=(to_string(count)+to_string(num));
                    num = a[j]-'0';
                    count = 1;
                }
            }
            // cout<<count<<" "<<num<<endl;
            temp+=(to_string(count)+to_string(num));
            a = temp;
            i++;
            cout<<a<<endl;
        }
        return a;
    }
};