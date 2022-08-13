class ParkingSystem {
private:
    int car[4] = {};
public:
    ParkingSystem(int big, int medium, int small) {
        car[1] += big;
        car[2] += medium;
        car[3] += small;
    }
    
    bool addCar(int carType) {
        car[carType]--;
        return car[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */