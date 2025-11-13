#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;

class Flight {
private:
    string flight_number_;
    string departure_time_;
    int seat_capacity_ = 0;
    int seat_sold_ = 0;

 
public:
    Flight(const std::string& flight_number,
           const std::string& departure_time,
           int seat_capacity,
           int seat_sold = 0)
        : flight_number_(flight_number),
        seat_capacity_(seat_capacity)
    {
        departure_time_ = departure_time;
        //seat_sold_ = seat_sold < 0 ? 0 : seat_sold;
        if (seat_sold_ < 0)  {
            seat_sold_ = 0;
        }
        else {
            seat_sold_ = seat_sold;
        }
    }

    // Getters
    const string& flightNumber() const  { return flight_number_; }
    const string& departureTime() const noexcept { return departure_time_; }
    int seatCapacity() const noexcept { return seat_capacity_; }
    int seatsSold() const noexcept { return seat_sold_; }
    int seatsAvailable() const noexcept { return seat_capacity_ - seat_sold_; }

    // Setters
    void setFlightNumber(const string& fn) { flight_number_ = fn; }
    void setDepartureTime(const string& dt) { departure_time_ = dt; }

    // Adjust capacity (if new capacity is less than seats already sold, reduce sold to fit)
    bool setSeatCapacity(int capacity) {
        if (capacity < 0)
        {
            capacity = 0; 
            return false;
        }
        seat_capacity_ = capacity;
        //if (seat_sold_ > seat_capacity_) seat_sold_ = seat_capacity_;
        return true;
    }

    
};