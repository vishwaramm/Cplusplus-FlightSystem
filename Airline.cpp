#include "Airline.h"

Airline::Airline(): Airline("") {}

Airline::Airline(std::string n): name(new std::string(n) ) {}

std::string Airline::getName() const {
    return *name;
}

void Airline::setName(std::string n) const {
    *name = n;
}

Airline::~Airline() {
    delete name;
}

std::ostream& operator<<(std::ostream& os, const Airline& a1)
{
    os << a1.getName() << "\n";
    return os;
}