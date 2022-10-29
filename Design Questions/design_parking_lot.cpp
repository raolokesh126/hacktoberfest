class ISlot {
    virtual int getId() = 0;  
};
    
class BigSlot : public ISlot {
private:
    int slotId;
public: 
    BigSlot(int id) {
        slotId = id;
    }
    
    int getId() {
        return slotId;
    }
};

class MediumSlot : public ISlot {
private:
    int slotId;
public: 
    MediumSlot(int id) {
        slotId = id;
    }
    
    int getId() {
        return slotId;
    }
};

class SmallSlot : public ISlot {
private:
    int slotId;
public: 
    SmallSlot(int id) {
        slotId = id;
    }
    
    int getId() {
        return slotId;
    }
};

class Factory {
private: 
    ISlot *iSlot;
public: 
    Factory() {
        
    }
    
    ISlot* work(int carType, int id) {
        if(carType == 1) {
            iSlot = new BigSlot(id);
        } else if(carType == 2) {
            iSlot = new MediumSlot(id);
        } else if(carType == 3) {
            iSlot = new SmallSlot(id);
        }
        return iSlot;
    }  
};

class ParkingSystem {
private: 
    unordered_set<ISlot*> bigSlots, mediumSlots, smallSlots;
    unordered_set<ISlot*> busyBigSlots, busyMediumSlots, busySmallSlots;
    
public:
    
    ParkingSystem(int big, int medium, int small) {
        initializeSpots(big, medium, small);
    }
    
    void initializeSpots(int big, int medium, int small) {
        int id = 0;
        Factory *factoryObj = new Factory();
        for(int i = 0; i < big; i++) {
            ISlot *curSlot = factoryObj->work(1, id++);
            bigSlots.insert(curSlot);
        }
        for(int i = 0; i < medium; i++) {
            ISlot *curSlot = factoryObj->work(1, id++);
            mediumSlots.insert(curSlot);
        }
        for(int i = 0; i < small; i++) {
            ISlot *curSlot = factoryObj->work(1, id++);
            smallSlots.insert(curSlot);
        }
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(bigSlots.size() > 0) {
                ISlot *curSlot = *bigSlots.begin();
                bigSlots.erase(curSlot);
                busyBigSlots.insert(curSlot);
                return true;
            }
        } else if(carType == 2) {
            if(mediumSlots.size() > 0) {
                ISlot *curSlot = *mediumSlots.begin();
                mediumSlots.erase(curSlot);
                busyMediumSlots.insert(curSlot);
                return true;
            }
        } else if(carType == 3) {
            if(smallSlots.size() > 0) {
                ISlot *curSlot = *smallSlots.begin();
                smallSlots.erase(curSlot);
                busySmallSlots.insert(curSlot);
                return true;
            }
        }
        return false;
    }
};
