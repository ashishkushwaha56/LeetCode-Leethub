class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a = big, b =medium, c = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) return a-->0;
        else if(carType == 2) return b-->0;
        else return c-->0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */