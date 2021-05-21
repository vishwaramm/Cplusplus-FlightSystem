// (c) s. trowbridge 2021
#include <iostream>

#include "Flight.h"

int main() {
    std::cout << "\n";

    // construct objects
    Airline *a1 = new Airline("Rebellion Air");
    Airline *a2 = new Airline("Empire Air");
    Airline *a3 = new Airline("Jawa Air");
    Airport *ap1 = new Airport("DAN", "Dantooine");
    Airport *ap2 = new Airport("END", "Endor");
    Airport *ap3 = new Airport("HOT", "Hoth");
    Airport *ap4 = new Airport("KES", "Kessel");
    Pilot *p1 = new Pilot("Darth Sidious");
    Pilot *p2 = new Pilot("Darth Plagueis");
    Pilot *p3 = new Pilot("Darth Bane");
    Flight *f1 = new Flight(111, *a1, *ap1, *ap3, *p1);
    std::cout << "OBJECTS CONSTRUCTED\n\n";
    /* end of phase 4 */

    std::cout << "PHASE 3 TEST *******************************************\n\n";

    /* print flight f1 */
    std::cout << *f1 << "\n";

    /* test various object mutators */
    a1->setName("Hogwarts Express");
    ap1->setName("Hogsmeade");
    ap2->setName("Diagon Alley");
    p1->setName("Darth Severus");

    /* test flight mutators */
    f1->setAirline(*a1);
    f1->setSource(*ap1);
    f1->setDestination(*ap2);
    f1->setPilot(*p1);

    /* test basic accessor functions */
    std::cout << f1->getAirline()->getName() << "\n";
    std::cout << f1->getSource()->getName() << "\n";
    std::cout << f1->getDestination()->getName() << "\n";
    std::cout << f1->getPilot() << "\n\n";

    /* print flight f1 */
    std::cout << *f1 << "\n";

    std::cout << "\nPHASE 3 COMPLETED ****************************************\n";
    /* end of phase 3 */

    std::cout << "\n";
    return 0;
}
