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

ostream &operator<<(ostream &os, const Flight &flight){
        os <<  flight.flight_number_ << "(" << flight.seat_capacity_ << ") departs at" ;
        os << flight.departure_time_ << " sold: " << flight.seat_sold_ ;
        os << "Seats \n";
        for(int i = 0; i < 10; ++i){
            if (!flight.additional_info_[i].empty()){
                os << "  - " << flight.additional_info_[i] << "\n";
            }
        }
        return os;
    }

bool Flight::sold_out (){
    if (seatsAvailable() == 0){
        return true;
    }
    else {
        return false;
    }   
}
bool Flight::add_additional_info(const string& info){
    bool added = false;
    for (int i = 0; i < 10; ++i){
        if (additional_info_[i].empty()){
            additional_info_[i] = info;
            added = true;
            break;
        }
    }
    if (!added){
        cout << "No space to add more additional info.\n";
    }
    return added;
}