#include "Flight.h"

int main() {
    

    std::cout << "Hello, World!\n";
    Flight flight1("AA123", "2024-07-01 10:00", 150, 50);
    cout << "Flight Number: " << flight1.flightNumber() << "\n";
    cout << "Departure Time: " << flight1.departureTime() << "\n";      
    cout << "Seat Capacity: " << flight1.seatCapacity() << "\n";
    cout << "Seats Sold: " << flight1.seatsSold() << "\n";
    cout << "Seats Available: " << flight1.seatsAvailable() << "\n";

   
    cin.get();
    return 0;
}