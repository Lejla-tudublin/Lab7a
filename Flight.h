#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
class Flight {
private:
    string flight_number_;
    string departure_time_;
    int seat_capacity_ = 0;
    int seat_sold_ = 0;
    string additional_info_[10];

 
public:
    Flight( std::string flight_number = "",
            std::string departure_time = "",
           int seat_capacity = 50,
           int seat_sold = 0);

    // Getters
    const string& flightNumber() const  { return flight_number_; }
    const string& departureTime() const noexcept { return departure_time_; }
    int seatCapacity() const noexcept { return seat_capacity_; }
    int seatsSold() const noexcept { return seat_sold_; }
    int seatsAvailable() const noexcept { return seat_capacity_ - seat_sold_; }
    
    // Setters
    void setFlightNumber(const string& fn) { flight_number_ = fn; }
    void setDepartureTime(const string& dt) { departure_time_ = dt; }
    bool add_additional_info(const string& info);
    // Adjust capacity (if new capacity is less than seats already sold, reduce sold to fit)
    bool setSeatCapacity(int capacity);
    // Sell seats
    bool sellSeats(int number);
    friend ostream& operator<<(ostream& os, const Flight& flight);
    bool sold_out ();
};