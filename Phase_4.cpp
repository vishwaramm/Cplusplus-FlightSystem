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
    Passenger *pas1 = new Passenger("Boba Fett");
    Passenger *pas2 = new Passenger("Zam Wesell");
    Passenger *pas3 = new Passenger("Qui-Gon Jinn");
    Passenger *pas4 = new Passenger("Mace Windu");
    Passenger *pas5 = new Passenger("Kit Fisto");
    Passenger *pas6 = new Passenger("Barriss Offee");
    Passenger *pas7 = new Passenger("Eeth Koth");
    Passenger *pas8 = new Passenger("Count Dooku");
    Passenger *pas9 = new Passenger("Aayla Secura");
    Flight *f1 = new Flight(111, *a1, *ap1, *ap3, *p1);
    Flight *f2 = new Flight(222, *a2, *ap3, *ap4, *p2);
    Flight *f3 = new Flight(333, *a3, *ap1, *ap2, *p3);
    std::cout << "OBJECTS CONSTRUCTED\n\n";

    std::cout << "PHASE 4 **************************************************\n\n";
    /* add passengers */
    std::cout << "ADD PASSENGERS *******************************************\n";
    f1->addPassenger(*pas1);
    f1->addPassenger(*pas2);
    f1->addPassenger(*pas3);
    f2->addPassenger(*pas2);
    f2->addPassenger(*pas3);
    f2->addPassenger(*pas4);
    f2->addPassenger(*pas5);
    std::cout << *f1;             // display flight f1
    std::cout << *f2;             // display flight f2
    std::cout << *pas1;           // display passenger pas1
    std::cout << *pas2;           // display passenger pas2


    /* remove passengers */
    std::cout << "\n\n\nREMOVE PASSENGERS ***************************************\n";
    std::cout << "REMOVE " << pas1->getName() << " from " << f1->getNumber() << "\n";
    f1->removePassenger(*pas1);
    std::cout << *f1;             // display flight f1
    std::cout << *pas1;           // display passenger pas4


    std::cout << "\n\n\nCANCEL FLIGHT ***************************************\n";
    std::cout << "CANCEL FLIGHT " << f2->getNumber() << "\n";

    /* before cancel */
    std::cout << "\nBEFORE CANCEL" << "\n";
    std::cout << *f2;             // display flight
    std::cout << *ap3;             // display flight f2 departure airport
    std::cout << *p2;             // display flight f2 pilot
    std::cout << *pas2;           // display flight f2 passenger

      /* after cancel */
    f2->cancel();
    std::cout << "\n\nAFTER CANCEL" << "\n";
    std::cout << *f2;             // display flight after cancel
    std::cout << *ap3;             // display flight f2 departure airport after flight cancel
    std::cout << *p2;             // display flight f2 pilot airport after flight cancel
    std::cout << *pas2 << "\n";   // display flight f2 passenger airport after flight cancel
    std::cout << "END PHASE 4 **************************************************\n";
    /* end of phase 4 */

    std::cout << "\n";
    return 0;
}
