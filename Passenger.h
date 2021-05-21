#pragma once
#include <iostream>
#include "MyArray.h"
#include "Flight.h"
#include "Person.h"

class Flight;
// template<typename T>
// class MyArray;

class Passenger : public Person {
    private:
        MyArray<Flight*> flights;
    public:
        Passenger();
        Passenger(std::string n);
        ~Passenger();
        void addFlight(Flight *f) override;
        void removeFlight(Flight *f) override;
        void cancelFights();
    friend std::ostream& operator<<(std::ostream& os, const Passenger& p1);
};