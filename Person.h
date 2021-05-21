#pragma once
#include <iostream>
#include "Flight.h"

class Flight;

class Person{
private:
    std::string *name;
public:
    Person(): Person("") {}
    Person(std::string n): name(new std::string(n)){}
    virtual std::string getName() const {
      return *name;
    }
    virtual void setName(std::string n) const {
      *name = n;
    }
    virtual void addFlight(Flight *f) = 0;
    virtual void removeFlight(Flight *f) = 0;

    virtual ~Person() {
        delete name;
    }
    virtual bool operator==(const Person &p1) {
      if (p1.getName() == getName()) {
        return true;
      }

      return false;
    }
};