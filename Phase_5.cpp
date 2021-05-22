// (c) s. trowbridge 2021
#include <iostream>
#include <iomanip>

#include "Flight.h"

// containers
MyArray<Airline*> airlines;
MyArray<Airport*> airports;
MyArray<Passenger*> passengers;
MyArray<Pilot*> pilots;
MyArray<Flight*> flights;

// store data into containers
void read() {
    std::cout << "Airlines: " << airlines;
    std::cout << "adding airlines\n";
    airlines.push_back( new Airline("Rebellion Air") );
    airlines.push_back( new Airline("Empire Air") );
    airlines.push_back( new Airline("Jawa Air") );
    
    std::cout << "adding airports\n";
    airports.push_back( new Airport("DAN", "Dantooine") );
    airports.push_back( new Airport("END", "Endor") );
    airports.push_back( new Airport("HOT", "Hoth") );
    airports.push_back( new Airport("KES", "Kessel") );
    
    std::cout << "adding pilots\n";
    pilots.push_back( new Pilot("Darth Sidious") );
    pilots.push_back( new Pilot("Darth Plagueis") );
    pilots.push_back( new Pilot("Darth Bane") );
    
    std::cout << "adding passengers\n";
    passengers.push_back( new Passenger("Boba Fett") );
    passengers.push_back( new Passenger("Zam Wesell") );
    passengers.push_back( new Passenger("Qui-Gon Jinn") );
    passengers.push_back( new Passenger("Mace Windu") );
    passengers.push_back( new Passenger("Kit Fisto") );
    passengers.push_back( new Passenger("Barriss Offee") );
    passengers.push_back( new Passenger("Eeth Koth") );
    passengers.push_back( new Passenger("Count Dooku") );
    passengers.push_back( new Passenger("Aayla Secura") );
    std::cout << "adding flights\n";
    flights.push_back( new Flight(111, *airlines[0], *airports[0], *airports[1], *pilots[0]) );
    flights.push_back( new Flight(222, *airlines[1], *airports[2], *airports[3], *pilots[0]) );
    flights.push_back( new Flight(333, *airlines[2], *airports[2], *airports[0], *pilots[0]) );
    std::cout << "adding passengers to flights \n";
    flights[0]->addPassenger(*passengers[0]);
    flights[0]->addPassenger(*passengers[1]);
    flights[0]->addPassenger(*passengers[3]);
    flights[0]->addPassenger(*passengers[6]);
    flights[0]->addPassenger(*passengers[7]);
    flights[0]->addPassenger(*passengers[2]);
    flights[1]->addPassenger(*passengers[1]);
    flights[1]->addPassenger(*passengers[3]);
    flights[1]->addPassenger(*passengers[4]);
    flights[1]->addPassenger(*passengers[5]);
    flights[1]->addPassenger(*passengers[7]);
    flights[1]->addPassenger(*passengers[2]);
    flights[1]->addPassenger(*passengers[0]);

    std::cout << "Finished read\n";
}

void listPilots() {
    std::cout << "\nPILOTS:\n";
    for(int i=0; i< pilots.getSize();i++) {
        std::cout << i << ": " << *(pilots[i]);
    }
    std::cout << "\n";
}

void listPassengers() {
    std::cout << "\nPASSENGERS:\n";
    for(int i=0; i< passengers.getSize();i++) {
        std::cout << i << ": " << *(passengers[i]);
    }
    std::cout << "\n";
}

void listAirports() {
    std::cout << "\nAIRPORTS:\n";
    for(int i=0; i< airports.getSize();i++) {
        std::cout << i << ": " << *(airports[i]);
    }
    std::cout << "\n";
    // listMyArray(airports, "Airports");
}

void listAirlines() {
    std::cout << "\nAIRLINES:\n";
    for(int i=0; i< airlines.getSize();i++) {
        std::cout << i << ": " << *(airlines[i]);
    }
    std::cout << "\n";
}

void listFlights() {
    std::cout << "\nFLIGHTS:\n";
    for(int i=0; i< flights.getSize();i++) {
        std::cout << i << ": " << *(flights[i]);
    }
    std::cout << "\n";
}

void deleteFlight() {
    listFlights();
    int index;
    std::cout << "SELECT A FLIGHT BY INDEX TO DELETE: ";
    std::cin >> index;

    if (index < flights.getSize() && index >= 0) {
        Flight *f = flights[index];
        f->cancel();
        f = NULL;
        delete f;
        flights.erase(index);
        std::cout << "Successfully deleted flight at index: " << index << "\n";
    }
}

void deleteAirport() {
    listAirports();
    int index;
    std::cout << "SELECT AN AIRPORT BY INDEX TO DELETE: ";
    std::cin >> index;

    if (index < airports.getSize() && index >= 0) {
        Airport *a = airports[index];
        a->closeAirport();
        airports.erase(index);
        delete a;
        std::cout << "Successfully deleted airport at index: " << index << "\n";
    }

}

void deletePassenger() {
    listPassengers();
    int index;
    std::cout << "SELECT A PASSENGER BY INDEX TO DELETE: ";
    std::cin >> index;

    if (index < passengers.getSize() && index >= 0) {
        Person *p = passengers[index];
        for (int i = 0; i < flights.getSize(); i++) {
            flights[i]->removePassenger(*p);
        }
        passengers.erase(index);
        delete p;
        std::cout << "Successfully deleted passenger at index: " << index << "\n";
    }
}

void createPassenger() {
    std::cout << "\nCreate a Passenger:\n";
    std::cout << "ENTER PASSENGER NAME: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    passengers.push_back(new Passenger(name));
    std::cout << "\nSuccessfully added new Passenger\n";
}

void createAirport() {
    std::cout << "\nCreate a new Airport:\n";
    std::cout << "ENTER AIRPORT NAME: ";
    std::string name;
    std::string symbol;
    std::getline(std::cin >> std::ws, name);
    std::cout << "ENTER AIPORT SYMBOL: ";
    std::getline(std::cin >> std::ws, symbol);
    
    airports.push_back(new Airport(symbol, name));
    std::cout << "\nSuccessfully added new Airport\n";

}

void createFlight() {
    std::cout << "\nADD NEW FLIGHT:\n";
    std::cout << "ENTER FLIGHT NUMBER: ";
    int number;
    int airline;
    int source;
    int destination;
    int pilot;

    std::cin >> number;
    listAirlines();
    std::cout << "PICK AIRLINE BY INDEX: ";
    std::cin >> airline;

    listAirports();
    std::cout << "PICK SOURCE AIRPORT BY INDEX: ";
    std::cin >> source;

    listAirports();
    std::cout << "PICK DESTINATION AIRPORT BY INDEX: ";
    std::cin >> destination;

    listPilots();
    std::cout << "PICK PILOT BY INDEX: ";
    std::cin >> pilot;
    
    flights.push_back(new Flight(number, *airlines[airline], *airports[source], *airports[destination], *pilots[pilot]));
    std::cout << "\nSuccessfully added new Flight\n";

}

void changePilot(Flight *f) {
    std::cout << "\nCHANGE PILOT:\n";
    listPilots();
    std::cout << "SELECT PILOT BY INDEX: ";
    int pilot;
    std::cin >> pilot;
    f->setPilot(*(pilots[pilot]));
    std::cout << "\nSuccessfully changed Pilot\n";
}

void changeSourceAirport(Flight *f) {
    std::cout << "\nCHANGE SOURCE AIRPORT:\n";
    listAirports();
    std::cout << "SELECT SOURCE AIRPORT BY INDEX: ";
    int source;
    std::cin >> source;
    f->setSource(*(airports[source]));
    std::cout << "\nSuccessfully changed Source Airport\n";
}

void changeDestinationAirport(Flight *f) {
    std::cout << "\nCHANGE DESTINATION AIRPORT:\n";
    listAirports();
    std::cout << "SELECT DESTINATION AIRPORT BY INDEX: ";
    int destination;
    std::cin >> destination;
    f->setDestination(*(airports[destination]));
    std::cout << "\nSuccessfully changed Destination Airport\n";
}

void addPassenger(Flight *f) {
    std::cout << "\nADD PASSENGER:\n";
    listPassengers();
    std::cout << "SELECT PASSENGER BY INDEX: ";
    int passenger;
    std::cin >> passenger;
    f->addPassenger(*(passengers[passenger]));
    std::cout << "\nSuccessfully added Passenger with index: " << passenger << "\n";
}

void removePassenger(Flight *f) {
    std::cout << "\nREMOVE PASSENGER:\n";
    listPassengers();
    std::cout << "SELECT PASSENGER BY INDEX: ";
    int passenger;
    std::cin >> passenger;
    f->removePassenger(*(passengers[passenger]));
    std::cout << "\nSuccessfully removed Passenger at index: " << passenger << "\n";
}

void flightSubmenu(int index) {
    std::cout << "index: " << index;
    if (index >= 0 && index < flights.getSize()) {
        Flight *f = flights[index];
        int input;
        while (input != 6) {
            std::cout << "\n*******************************\n";
            std::cout << "FLIGHT " << f->getNumber() << " SUBMENU:";
            std::cout << "\n*******************************\n";
            std::cout << "1 Change Pilot\n";
            std::cout << "2 Change Departure Airport\n";
            std::cout << "3 Change Arrival Airport\n";
            std::cout << "4 Add Passenger\n";
            std::cout << "5 Remove Passenger\n";
            std::cout << "6 Flights Menu\n";
            std::cout << "\nSELECT AN OPTION: ";
            std::cin >> input;
            switch(input) {
                case 1:
                    changePilot(f);
                    break;
                case 2:
                    changeSourceAirport(f);
                    break;
                case 3:
                    changeDestinationAirport(f);
                    break;
                case 4:
                    addPassenger(f);
                    break;
                case 5:
                    removePassenger(f);
                    break;
            }
        }
    }
}

int selectFlight() {
    listFlights();
    int index;
    std::cout << "SELECT A FLIGHT BY INDEX: ";
    std::cin >> index;
    return index;
}

void flightsMenu() {
    int input;
    while (input != 5) {
        std::cout << "\n*******************************\n";
        std::cout << "FLIGHTS MENU:";
        std::cout << "\n*******************************\n";
        std::cout << "1 List Flights\n";
        std::cout << "2 Add Flight\n";
        std::cout << "3 Delete Flight\n";
        std::cout << "4 Select Flight\n";
        std::cout << "5 Main Menu\n";
        std::cout << "\nSELECT AN OPTION: ";
        std::cin >> input;
        switch(input) {
            case 1:
                listFlights();
                break;
            case 2:
                createFlight();
                break;
            case 3:
                deleteFlight();
                break;
            case 4: 
                flightSubmenu(selectFlight());
                break;
        }
    }
}

void airportsMenu() {
    int input;
    while (input != 4) {
        std::cout << "\n*******************************\n";
        std::cout << "AIRPORTS MENU:";
        std::cout << "\n*******************************\n";
        std::cout << "1 List Airports\n";
        std::cout << "2 Create Airport\n";
        std::cout << "3 Delete Airport\n";
        std::cout << "4 Main Menu\n";
        std::cout << "\nSELECT AN OPTION: ";
        std::cin >> input;
        switch(input) {
            case 1:
                listAirports();
                break;
            case 2:
                createAirport();
                break;
            case 3:
                deleteAirport();
                break;
        }
    }
}

void passengersMenu() {
    int input;
    while (input != 4) {
        std::cout << "\n*******************************\n";
        std::cout << "PASSENGERS MENU:";
        std::cout << "\n*******************************\n";
        std::cout << "1 List Passengers\n";
        std::cout << "2 Create Passenger\n";
        std::cout << "3 Delete Passenger\n";
        std::cout << "4 Main Menu\n";
        std::cout << "\nSELECT AN OPTION: ";
        std::cin >> input;
        switch(input) {
            case 1:
                listPassengers();
                break;
            case 2:
                createPassenger();
                break;
            case 3:
                deletePassenger();
                break;
        }
    }
}

void mainMenu() {
    int input;
    while (input != 4) {
        std::cout << "\n*******************************\n";
        std::cout << "MAIN MENU:";
        std::cout << "\n*******************************\n";
        std::cout << "1 Airports\n";
        std::cout << "2 Flights\n";
        std::cout << "3 Passengers\n";
        std::cout << "4 End program\n";
        std::cout << "\nSELECT AN OPTION: ";
        std::cin >> input;
        switch(input) {
            case 1:
                airportsMenu();
                break;
            case 2:
                flightsMenu();
                break;
            case 3:
                passengersMenu();
                break;
        }
    }
}

int main() {
    std::cout << "\n";
    // read data into the containers
    read();
    mainMenu();
    std::cout << "\n";
    return 0;
}
