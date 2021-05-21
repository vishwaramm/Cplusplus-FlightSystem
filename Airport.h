#pragma once
#include <iostream>
#include "MyArray.h"
#include "Flight.h"

class Flight;

class Airport{
private:
    std::string *name;
    std::string *symbol;
    MyArray<Flight*> arrivals;
    MyArray<Flight*> departures;
public:
    Airport();
    Airport(std::string s, std::string n);
    std::string getName() const;
    void setName(std::string n) const;
    std::string getSymbol() const;
    void setSymbol(std::string sn) const;
    void addArrival(Flight f);
    void addDeparture(Flight f);
    void removeArrival(Flight f);
    void removeDeparture(Flight f);
    void closeAirport();
    ~Airport();
    friend std::ostream& operator<<(std::ostream& os, const Airport& a1);
};