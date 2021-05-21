#include "MyArray.h"
#include "Flight.h"
#include "Pilot.h"
#include "Person.h"

Pilot::Pilot(): Person() {}

Pilot::Pilot(std::string n): Person(n){
}

Pilot::~Pilot() {}

void Pilot::addFlight(Flight *f) {
    int index = flights.getIndex(f);

    if (index >= 0) {
        f->setPilot(*this);
        flights.push_back(f);
    }
}

void Pilot::removeFlight(Flight *f) {
    int index = flights.getIndex(f);

    if (index >= 0) {
        f->nullPilot();
        flights.erase(index);
    }
}

std::ostream& operator<<(std::ostream& os, const Pilot& p1)
{
    os << p1.getName() << "\n" << p1.flights;
    return os;
}