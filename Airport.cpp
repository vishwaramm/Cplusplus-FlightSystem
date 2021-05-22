#include "Airport.h"

Airport::Airport(): Airport("", "") {}
    
Airport::Airport(std::string s, std::string n): name(new std::string(n)), symbol(new std::string(s)) {}

std::string Airport::getName() const {
    return *name;
}
void Airport::setName(std::string n) const {
    *name = n;
}
std::string Airport::getSymbol() const {
    return *symbol;
}
void Airport::setSymbol(std::string s) const {
    *symbol = s;
}

Airport::~Airport() {
    delete name;
    delete symbol;
}

void Airport::addArrival(Flight f) {
    int index = arrivals.getIndex(&f);

    if (index == -1) {
        arrivals.push_back(&f);
    }
}

void Airport::addDeparture(Flight f) {
    int index = departures.getIndex(&f);

    if (index == -1) {
        departures.push_back(&f);
    }
}

void Airport::removeArrival(Flight f) {
    int index = arrivals.getIndex(&f);

    if (index >= 0) {
        arrivals.erase(index);
    }
}

void Airport::removeDeparture(Flight f) {
    int index = departures.getIndex(&f);

    if (index >= 0) {
        departures.erase(index);
    }
}
void Airport::closeAirport() {
    for (int i = 0; i < arrivals.getSize(); i++) {
        Flight *currFlight = arrivals[i];

        if (currFlight->getSource() == this)
            currFlight->nullSource();
        
        if (currFlight->getDestination() == this)
            currFlight->nullDestination();
    }

    for (int i = 0; i < departures.getSize(); i++) {
        Flight *currFlight = departures[i];
        if (currFlight->getSource() == this)
            currFlight->nullSource();
        
        if (currFlight->getDestination() == this)
            currFlight->nullDestination();
    }
}

std::ostream& operator<<(std::ostream& os, const Airport& a1)
{
    os << a1.getSymbol() << ": " <<  a1.getName() << "\n";

    int arrivalSize = a1.arrivals.getSize();
    int departureSize = a1.departures.getSize();

    // os << " with arrivals: ";

    // if (arrivalSize == 0) {
    //     os << "None";
    // } else {
    //     for(int i=0; i< a1.arrivals.getSize();i++) {
    //         os << i << " " << *(a1.arrivals[i]) << ", ";
    //     }
    // }

    // os << " and Departures: ";

    // if (departureSize == 0) {
    //     os << "None";
    // } else {
    //    for(int i=0; i< a1.departures.getSize();i++) {
    //         os << i << " " << *(a1.departures[i]) << ", ";
    //     }
    // }

    // os << "\n";
    return os;
}