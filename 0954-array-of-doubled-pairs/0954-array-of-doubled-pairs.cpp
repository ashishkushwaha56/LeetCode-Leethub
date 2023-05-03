class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> pos,neg;
        int cnt = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]>0) pos[arr[i]]++;
            else if(arr[i]<0) neg[-arr[i]]++;
            else cnt++;
        }
        int a = 0;
        while(true){
            auto it = pos.begin();
            if(it == pos.end()) break;
            if(pos.find(2*(*it).first)!=pos.end()){
                a = min(pos[2*(*it).first],pos[(*it).first]);
                pos[2*(*it).first]-=a;
                pos[(*it).first]-=a;
                if(pos[2*(*it).first] == 0) pos.erase(2*(*it).first);
                if(pos[(*it).first] == 0) pos.erase((*it).first);
            }
            else{
                return false;
            }
        }
        
        while(true){
            auto it = neg.begin();
            if(it == neg.end()) break;
            if(neg.find(2*(*it).first)!=neg.end()){
                a = min(neg[2*(*it).first],neg[(*it).first]);
                neg[2*(*it).first]-=a;
                neg[(*it).first]-=a;
                if(neg[2*(*it).first] == 0) neg.erase(2*(*it).first);
                if(neg[(*it).first] == 0) neg.erase((*it).first);
            }
            else{
                return false;
            }
        }
        if(cnt&1) return false;
        return true;
    }
};