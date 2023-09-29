class ParkingSystem {
private:
    int spots[3];
public:
    ParkingSystem(int big, int medium, int small) {
        spots[0]=big;
        spots[1]=medium;
        spots[2]=small;
    }
    
    bool addCar(int carType) {
        if(spots[carType-1]>0){
            spots[carType-1]--;
            return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */