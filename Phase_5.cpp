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
    std::cout << "airports: " << airports;
    
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

void listFlights() {
    std::cout << "Current Flights:\n";
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
        Flight f = *(flights[index]);
        f.cancel();
        flights.erase(index);
    }
}

void flightSubmenu(int index) {
    std::cout << "index: " << index;
    if (index >= 0 && index < flights.getSize()) {
        Flight f = *(flights[index]);
        int input;
        while (input != 6) {
            std::cout << "\n*******************************\n";
            std::cout << "FLIGHT " << f.getNumber() << " SUBMENU:";
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
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
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
                break;
            case 2:
                break;
            case 3:
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
                break;
            case 2:
                break;
            case 3:
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
