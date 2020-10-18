#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <mutex>
#include <condition_variable>
#include <cctype>
#include <functional>
#include <exception>
#include <stdexcept>
#include <thread>
#include <climits>
#include <float.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <time.h> 

using namespace std;

// https://www.educative.io/courses/grokking-the-object-oriented-design-interview/gxM3gRxmr8Z

enum VehicleSize { Small, Medium, Large };

class ParkingSpot {
public:
    ParkingSpot(int level, int number, VehicleSize size) {
        level=level;
        number=number;
        size=size;
    }
    bool isAvailable() {
        return vehicle==NULL;
    }

    bool canFitVehicle(Vehicle* vehicle) {}
    void removeVehicle(Vehicle* vehicle) {}
private:
    int level;
    int number;
    VehicleSize size;
    Vehicle* vehicle;
};

class Vehicle {
public:
    virtual bool canFitInSpot(ParkingSpot spot)=0;
    int getSpotsNeeded() {
        return spotsNeeded;
    }
    int getSize() {
        return size;
    }
protected:
    string licensePlate;
    VehicleSize size;
    int spotsNeeded;
    vector<ParkingSpot> parkingSpots;
};

class Bus: public Vehicle {
public:
    Bus() {
        spotsNeeded = 5;
        size = Large;
    }
    bool canFitInSpot(ParkingSpot spot) {}
};

class Car: public Vehicle {
public:
    Car() {
        spotsNeeded = 1;
        size = Medium;
    }
    bool canFitInSpot(ParkingSpot spot) {}
};

class Motocycle: public Vehicle {
public:
    Motocycle() {
        spotsNeeded = 1;
        size = Small;
    }
    bool canFitInSpot(ParkingSpot spot) {}
};

class Level {
public:
    Level(int number): levelNumber(number) {}
    bool parkVehicle(Vehicle* vehicle) {}
    void onVehicleLeave(Vehicle* vehicle) {}

private:
    int levelNumber;
    int availableSpots;
    vector<ParkingSpot> spots;
    bool parkStartingFromSpot(int number, Vehicle* vehicle) {}
    int findAvailableSpot(Vehicle* vehicle) {}
};

class ParkingLot {
public:
    ParkingLot() {}

    bool parkVehicle(Vehicle* vehicle) {}

private:
    vector<Level> levels;
    const int numberLevels=5;
};

int main(int argc, char** argv) {
    return 0;    
}

