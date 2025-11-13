#include "Flight.h"

Flight::Flight(std::string flight_number, std::string departure_time, int seat_capacity, int seat_sold)
 : flight_number_(flight_number), seat_capacity_(seat_capacity){
        departure_time_ = departure_time;
        //seat_sold_ = seat_sold < 0 ? 0 : seat_sold;
        if (seat_sold_ < 0)  {
            seat_sold_ = 0;
        }
        else {
            seat_sold_ = seat_sold;
        }
    }
bool Flight::setSeatCapacity(int capacity)
{
    if (capacity < 0)
    {
        capacity = 0;
        return false;
    }
    seat_capacity_ = capacity;
    // if (seat_sold_ > seat_capacity_) seat_sold_ = seat_capacity_;
    return true;
}

bool Flight::sellSeats(int number){
    if (number < 0) {
        return false;
    }
    if (seat_sold_ + number <= seat_capacity_) {
        seat_sold_ += number;
        return true;
    }
    cout << "Not enough available seats to sell " << number << " seats.\n";
    return false;
}