// (c) s. trowbridge 2021
#include <iostream>

#include "Flight.h"

int main() {
    std::cout << "\n";

    std::cout << "PHASE 2 TEST *******************************************\n\n";

    std::cout << "CONSTRUCTOR/ACCESSORS TEST\n\n";
    /* construct airlines */
    Airline *a1 = new Airline("Rebellion Air");
    std::cout << "Airline: " << a1->getName() << "\n";

    /* construct airports */
    Airport *ap1 = new Airport("DAN", "Dantooine");
    Airport *ap2 = new Airport("END", "Endor");
    std::cout << "Airport: " << a1->getName() << "\n";

    /* construct pilots */
    Pilot *p1 = new Pilot("Darth Sidious");
    std::cout << "Pilot: " << p1->getName() << "\n";

    /* construct passenger */
    Passenger *pas1 = new Passenger("Boba Fett");
    std::cout << "Passenger: " << pas1->getName() << "\n";

    /* construct flights */
    Flight *f1 = new Flight(111, *a1, *ap1, *ap2, *p1);

    /* << operator overloads */
    std::cout << "\n\nOPERATOR << OVERLOADS TEST\n\n";
    std::cout << *f1 << "\n";
    std::cout << *ap1 << "\n";
    std::cout << *p1 << "\n";
    std::cout << *pas1 << "\n";

    std::cout << "PHASE 2 COMPLETED **************************************\n\n";
    /* end of phase 4 */

    std::cout << "\n";
    return 0;
}
