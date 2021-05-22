#include "MyArray.h"
#include "Flight.h"
#include "Passenger.h"
#include "Person.h"

Passenger::Passenger() : Person() {}

Passenger::Passenger(std::string n) : Person(n) {
}

Passenger::~Passenger() {}

void Passenger::addFlight(Flight &f) {
    int index = flights.getIndex(&f);

    if (index >= 0) {
        f.addPassenger(*this);
        flights.push_back(&f);
    }
}

void Passenger::removeFlight(Flight &f) {
    int index = flights.getIndex(&f);

    if (index >= 0) {
        f.removePassenger(*this);
        flights.erase(index);
    }
}

void Passenger::cancelFights() {
    for (int i = 0; i < flights.getSize(); i++) {
        Flight *f = flights[i];
        f->removePassenger(*this);
    }
}

std::ostream& operator<<(std::ostream& os, const Passenger& p1)
{
    os << p1.getName() << "\n" << p1.flights;
    return os;
}