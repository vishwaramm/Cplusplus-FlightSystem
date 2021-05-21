#include "Flight.h"
#include "MyArray.h"
#include "Person.h"

Flight::Flight(): Flight(0, *(new Airline()), *(new Airport()), *(new Airport()), *(new Pilot())) {}

Flight::Flight(int n, Airline &a1, Airport &o, Airport &d, Pilot &p):
    airline(&a1),
    number(n),
    source(&o),
    destination(&d),
    pilot(&p) {
        source->addDeparture(*this);
        destination->addArrival(*this);
        pilot->addFlight(this);
    }

int Flight::getNumber() const {
    return number;
}

Flight::~Flight() {
}

Airline* Flight::getAirline() const {
    return airline;
}

Airport* Flight::getSource() const {
    return source;
}

Airport* Flight::getDestination() const {
    return destination;
}

std::string Flight::getPilot() const {
    if (pilot != nullptr) {
        return pilot->getName();
    }

    return "No Pilot";
}

Person* Flight::getPassenger(int index) const {
    if (index < passengers.getSize()) {
        return passengers[index];
    }

    return nullptr;
}

void Flight::setAirline(Airline a) {
    airline = &a;
}

void Flight::setSource(Airport s) {
    if (source != nullptr) {
        source->removeDeparture(*this);
    }
    source = &s;
    source->addArrival(*this);
}

void Flight::nullDestination() {
    destination = nullptr;
}

void Flight::nullPilot() {
    pilot = nullptr;
}

void Flight::nullSource() {
    source = nullptr;
}

void Flight::setDestination(Airport d) {
    if (destination != nullptr) {
        destination->removeArrival(*this);
    }
    destination = &d;
    destination->addArrival(*this);
}

void Flight::setPilot(Pilot p) {
    if (pilot != nullptr) {
        pilot->removeFlight(this);
    }
    pilot = &p;
    pilot->addFlight(this);
}

void Flight::addPassenger(Person &p) {
    int index = passengers.getIndex(&p);

    if (index == -1) {
        passengers.push_back(&p);
    }
}

void Flight::removePassenger(Person &p) {
    int index = passengers.getIndex(&p);

    if (index >= 0) {
        passengers.erase(index);
    }
}

void Flight::listPassengers() {
    std::cout << "Passengers:\n";

    std::cout << passengers;
}

int Flight::getNumPassengers() {
    int num = passengers.getSize();
    return num;
}
void Flight::cancel() {
    source->removeDeparture(*this);
    destination->removeArrival(*this);
    pilot->removeFlight(this);
    for (int i = 0; i < passengers.getSize(); i++) {
        Person p = *(passengers[i]);
        p.removeFlight(this);
    }
}

bool Flight::operator==(const Flight& f1) {
    if (f1.getNumber() == getNumber()) {
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const Flight& f1)
{
    os << "Flight " << 
    f1.getNumber() << 
    " departing " << 
    f1.getSource()->getName() << 
    " arriving at " << 
    f1.getDestination()->getName() 
    << " with pilot " 
    << f1.getPilot() << "\n";

    // os << f1.passengers;
    return os;
}