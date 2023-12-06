#include <iostream>

#include "string"

class Singleton {
   public:
    // Static method to access the singleton instance
    static Singleton& getInstance() {
        // If the instance doesn't exist, create it
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }

    // Public method to perform some operation
    void doSomething() {
        std::cout << "Singleton is doing sth..." << std::endl;
    }

    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

   private:
    // Private constructor to prevent external instantiation
    Singleton() {
        std::cout << "Singleton instance created (constructor)." << std::endl;
    }

    // Private destructor to prevent external deletion
    ~Singleton() {
        std::cout << "Singleton instance destroyed (destructor)." << std::endl;
    }

    // Private static instance variable
    static Singleton* instance;
};

class Vehicle {
   private:
    Vehicle() {
        std::cout << "Vehicle instance created (constructor)." << std::endl;
    }
    ~Vehicle() {
        std::cout << "Vehicle instance destroyed (destructor)." << std::endl;
    }

   public:
    static Vehicle& getInstance() {
        if (!instance) {
            std::cout << "step 1" << std::endl;
            instance = new Vehicle();
        }
        return *instance;
    }
    void doSomething() {
        std::cout << "Vehicle is doing sth..." << std::endl;
    }
    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;

    static Vehicle* instance;
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;
Vehicle* Vehicle::instance = nullptr;

int main() {
    // Access the Singleton instance
    // Singleton& obj_singleton = Singleton::getInstance();
    Vehicle& obj_vehicle = Vehicle::getInstance();

    // Use the Singleton instance
    // obj_singleton.doSomething();
    obj_vehicle.doSomething();

    return 0;
}
