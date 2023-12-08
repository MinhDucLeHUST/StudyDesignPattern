// C++ program to demonstrate factory method design pattern
#include <iostream>

using namespace std;

enum VehicleType {
    VT_TwoWheeler,
    VT_ThreeWheeler,
    VT_FourWheeler,
    VT_FiveWheeler
};

// Library classes
class Vehicle {
   public:
    virtual void printVehicleInfo() = 0;
    virtual ~Vehicle() {}
};

class TwoWheeler : public Vehicle {
   public:
    void printVehicleInfo() {
        cout << "I am two wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle {
   public:
    void printVehicleInfo() {
        cout << "I am three wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
   public:
    void printVehicleInfo() {
        cout << "I am four wheeler" << endl;
    }
};

class VehicleFactory {
   public:
    Vehicle* build(VehicleType vehicleType) {
        if (vehicleType == VT_TwoWheeler)
            return new TwoWheeler();
        else if (vehicleType == VT_ThreeWheeler)
            return new ThreeWheeler();
        else if (vehicleType == VT_FourWheeler)
            return new FourWheeler();
        else
            return nullptr;
    }
};

class Client {
   public:
    Client() { pVehicle = nullptr; }

    void BuildVehicle(VehicleType vehicleType) {
        VehicleFactory* vf = new VehicleFactory();
        pVehicle = vf->build(vehicleType);

        delete vf;
    }

    ~Client() {
        if (pVehicle) {
            delete pVehicle;
            pVehicle = NULL;
        }
    }

    Vehicle* getVehicle() { return pVehicle; }

   private:
    Vehicle* pVehicle;
};

// Driver program
int main() {
    Client* pClient = new Client();

    pClient->BuildVehicle(VT_TwoWheeler);
    pClient->getVehicle()->printVehicleInfo();

    delete pClient;
    return 0;
}
