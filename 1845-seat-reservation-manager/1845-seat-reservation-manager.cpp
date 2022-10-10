class SeatManager {
public:
    vector<int> v;
    map<int,int> mb;
    int k;
    SeatManager(int n) {
        v.resize(n);
        for(int i = 0;i<n;i++){
            mb[i]++;
        }
    }
    
    int reserve() {
        auto it = mb.begin();
        k = (*it).first+1;
        mb.erase((*it).first);
        return k;
    }
    
    void unreserve(int seatNumber) {
        mb[seatNumber-1]++;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */