class ExamRoom {
public:
    vector<int> v;
    int d;
    ExamRoom(int n) {
        d=n;
    }
    
    int seat() {
        if(v.size() == 0) {
            v.push_back(0);
            return 0;
        }
        int t = max(v[0],d-1-v[v.size()-1]);
        for(int i = 1;i<v.size();i++){
            t=max(t,(v[i]-v[i-1])/2);
        }
        if(v[0] == t){
            v.insert(v.begin(),0); return 0;
        }
        for(int i = 0;i<v.size()-1;i++){
            if(t == (v[i+1]-v[i])/2){
                v.insert(v.begin()+(i+1),(v[i+1]+v[i])/2);
                return v[i+1];
            }
        }
        v.push_back(d-1);
        return d-1;
    }
    
    void leave(int p) {
        for(int i = 0;i<v.size();i++){
            if(v[i]==p) {
                v.erase(v.begin()+i);
                return;
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */