class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int flag = 0;
        if(x<y){
            flag = 1;
        }
        stack<int> temp;
        stack<int> a,b;
        int ans = 0;
        if(flag == 1){
            for(int i = 0;i<s.size();i++){
                if(s[i]!='a' and s[i]!='b'){
                    while(!temp.empty()){
                        if(temp.top() == 'a'){
                            if(!b.empty()){
                                b.pop();
                                ans+=x;
                            }
                            temp.pop();
                        }
                        else{
                            b.push(temp.top());
                            temp.pop();
                        }
                    }
                    while(!b.empty()){b.pop();}
                }
                else{
                    if(!temp.empty() and temp.top() == 'b' and s[i] == 'a'){
                        temp.pop();
                        ans+=y;
                    }
                    else{
                        temp.push(s[i]);
                    }
                }
            }
            while(!temp.empty()){
                        if(temp.top() == 'a'){
                            if(!b.empty()){
                                b.pop();
                                ans+=x;
                            }
                            temp.pop();
                        }
                        else{
                            b.push(temp.top());
                            temp.pop();
                        }
                    }
                   while(!b.empty()){b.pop();}
        }
        else{
            for(int i = 0;i<s.size();i++){
                if(s[i]!='a' and s[i]!='b'){
                    while(!temp.empty()){
                        if(temp.top() == 'b'){
                            if(!a.empty()){
                                a.pop();
                                ans+=y;
                            }
                            temp.pop();
                        }
                        else{
                            a.push(temp.top());
                            temp.pop();
                        }
                    }
                    while(!a.empty()){a.pop();}
                }
                else{
                    if(!temp.empty() and temp.top() == 'a' and s[i] == 'b'){
                        temp.pop();
                        ans+=x;
                    }
                    else{
                        temp.push(s[i]);
                    }
                }
                
            }
            while(!temp.empty()){
                        if(temp.top() == 'b'){
                            if(!a.empty()){
                                a.pop();
                                ans+=y;
                            }
                            temp.pop();
                        }
                        else{
                            a.push(temp.top());
                            temp.pop();
                        }
                    }
                    while(!a.empty()){a.pop();}
        }
        return ans;
    }
};