class ParkingSystem {
public:
    int b, m, s, currB=0, currM=0, currS=0;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1:
                if(currB<b) {
                    currB++;
                    return true;
                }
                break;
            case 2:
                if(currM<m) {
                    currM++;
                    return true;
                }
                break;
            case 3:
                if(currS<s) {
                    currS++;
                    return true;
                }
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */