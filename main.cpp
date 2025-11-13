#include "Flight.h"

int main() {
    

    std::cout << "Hello, World!\n";
    //Flight flight1("AA123", "2024-07-01 10:00", 150, 50);
    //Flight flight1 ("Default"); // Using default constructor
    Flight arr [5];
    cout << arr[0] << endl; // print first element;
    arr[1].setFlightNumber("AA123");
    arr[1].setDepartureTime("2024-07-01 10:00");
    arr[1].setSeatCapacity(150);    
    arr[1].sellSeats(50);
    arr[1].add_additional_info("In-flight WiFi available");
    arr[1].add_additional_info("Complimentary snacks"); 
    arr[1].add_additional_info("Extra legroom seats available");
    cout << arr[1] << endl; // print second element;
    cin.get();
    return 0;
}