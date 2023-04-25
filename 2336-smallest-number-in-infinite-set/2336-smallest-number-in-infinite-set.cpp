class SmallestInfiniteSet {
public:
    // set<int> s = {1};
    map<int,bool> mb;
    
    SmallestInfiniteSet() {
        for(int i = 1;i<1001;i++){
            mb[i] = true;
        }
    }
    
    int popSmallest() {
        auto it = mb.begin();
        while(it!=mb.end()){
            if((*it).second == true){
                break;
            }
            it++;
        }
        if(it!=mb.end()){ (*it).second=false; return ((*it).first);}
        else return -1;
    }
    
    void addBack(int num) {
        mb[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */