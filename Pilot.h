#pragma once
#include <iostream>
#include "MyArray.h"
#include "Person.h"
#include "Flight.h"

class Flight;
// template<typename T>
// class MyArray;

class Pilot : public Person {
    private:
        MyArray<Flight*> flights;
    public:
        Pilot();
        Pilot(std::string n);
        void addFlight(Flight &f) override;
        void removeFlight(Flight &f) override;
        ~Pilot();

    friend std::ostream& operator<<(std::ostream& os, const Pilot& p1);
};