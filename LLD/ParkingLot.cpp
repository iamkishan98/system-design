#include<bits/stdc++.h>
using namespace std;

typedef enum
{
    Small = 0x01,
    Compat = 0x02,
    Large = 0x04
} parking_spot_size;

typedef enum
{
    Occupied = 0x01,
    Free     = 0x02
} parking_spot_status;

class ParkingSpot;
class Vehicle
{
    public:
    parking_spot_size Size;
    int regId;
    ParkingSpot *parkingSpots;

    Vehicle(){}

    int getRegId(){ return this->regId;}

    void parkVehicle(ParkingSpot *parkingSpot, Vehicle *vehicle){
        for(int i = 0 ;i < this->Size ; i++){
            this->parkingSpots[i] = parkingSpot[i];
            this->parkingSpots[i].reserveParkingSpot(vehicle);
        }
    }

};

class Bike : public Vehicle{
    public:
    Bike(){}
    Bike(int regId)
    {
        this->Size = Small;
        this->regId = regId;
        this->parkingSpots = NULL;
    }
};

class Car : public Vehicle{
    public:
    Car(){}
    Car(int regId){
        this->Size = Compat;
        this->regId = regId;
        this->parkingSpots = NULL;
    }

};

class SUV: public Vehicle{
    public:
    SUV(){}
    SUV(int regId){
        this->Size = Large;
        this->regId = regId;
        this->parkingSpots = NULL;
    }
};

class ParkingLevel
{
    public:
    int maxParkingSpots;
    int level;
    int availableSpots;
    ParkingSpot *parkingSpots;

    ParkingLevel(int maxParkingSpots, int level){
        this->maxParkingSpots = maxParkingSpots;
        this->level = level;
        this->availableSpots = maxParkingSpots;
        for(int i=0; i < this->maxParkingSpots; i ++)
        {
            this->parkingSpots[i] = new ParkingSpot(this->level);
        }
    }


    bool freeParkingSpot(ParkingSpot *parkingSpot){
        parkingSpot->freeParkingSpot();
        availableSpots += 1;
    }

    bool getAvailableSpots(){ return this->availableSpots ;}

    parking_spot_status getSpotStatus(ParkingSpot *parkingSpot){
        if(parkingSpot->getParkingSpotStatus())
            return Free;
        else
            return Occupied;
    }

    ParkingSpot *getAvailableSlots(int numSpots)
    {
        int startIndex = -1;
        int endIndex = -1;
        bool found = false;
        for(int i=0; i < this->maxParkingSpots-(numSpots -1); i ++){
            startIndex = i;
            for(int j = i; j < (i+numSpots); j ++){
                if(! this->parkingSpots[j]->getParkingSpotStatus()) break;
                endIndex = j;
            }

            if(numSpots =  endIndex - startIndex + 1){
                found = true;
                break;
            }
        }

        if(found == true)
        {
            this->parkingSpots[startIndex];
        }
        return NULL;
    }

};

class ParkingSpot
{
    public:
    parking_spot_status status;
    int level;
    Vehicle *vehicle;

    ParkingSpot(int level){
        this->level = level;
        this->status = Free;
        this->vehicle = NULL;
    }

    bool getParkingSpotStatus(){
        if(this->status == Occupied) return false;
        return true;
    }

    bool changeStatusSpot(parking_spot_size status){ this->status = status ;}

    Vehicle *getParkedVehicle(){
        return this->vehicle;
    }

    bool reserveParkingSpot(Vehicle *vehicle)
    {
        if(this->getParkingSpotStatus())
        {
            this->vehicle = vehicle;
            this->changeStatusSpot(Occupied);
            return true;
        }
        return false;
    }

    void freeParkingSpot(){
        if(!this->getParkingSpotStatus()){
            this->status = Free;
            this->vehicle = NULL;
        }
    }

};

class ParkingLot
{
    public:
    int maxLevels;
    ParkingLevel *parkingLevels;
    int maxSpots;

    ParkingLot(int maxLevels, int maxSpots){
        this->maxLevels = maxLevels;
        this->maxSpots = maxSpots;
        for(int i=0; i< this->maxLevels; i++){
            this->parkingLevels[i] = new ParkingLevel(this->maxSpots, i);
        }
    }

};

int main()
{
    ParkingLot *parkingLot = new ParkingLot(2, 4);
    // New vehicl entry in parking lot
    Vehicle *b1 = new Bike(1234);
    Vehicle *c1 = new Car(2345);
    Vehicle *suv1 = new SUV(4567);
    // Level 1 parking
    ParkingSpot *spot = parkingLot->parkingLevels[0]->getAvailableSlots(b1->Size);
    if( NULL != spot)
    {
        b1->parkVehicle(spot,b1);
    }
    cout<<spot->getParkedVehicle()<<endl;
}

