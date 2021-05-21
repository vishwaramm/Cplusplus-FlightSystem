#pragma once
#include <iostream>
#include "MyArray.h"
#include "Passenger.h"
#include "Pilot.h"
#include "Airline.h"
#include "Airport.h"

class Airline;
class Airport;
class Pilot;

// template<typename T>
// class MyArray;

class Flight{
    private:
        int number;
        Airline *airline;
        Airport *source;
        Airport *destination;
        Pilot *pilot;
        MyArray<Person*> passengers;
    public:
        Flight();
        Flight(int n, Airline &a1, Airport &o, Airport &d, Pilot &p);
        int getNumber() const;
        Airport* getSource() const;
        Airport* getDestination() const;
        std::string getPilot() const;
        Airline* getAirline() const;
        Person* getPassenger(int index) const;
        void setAirline(Airline a);
        void setSource(Airport s);
        void setDestination(Airport d);
        void setPilot(Pilot p);
        void nullSource();
        void nullDestination();
        void nullPilot();
        void addPassenger(Person &p);
        void removePassenger(Person &p);
        void listPassengers();
        int getNumPassengers();
        void cancel();
        ~Flight();
        bool operator==(const Flight &f1);
    friend std::ostream& operator<<(std::ostream& os, const Flight& f1);
};