#pragma once

#include <map>
#include <vector>
#include "responses.h"

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    // маршрут + его остановки, в порядке добавления
    map<string, vector<string>> buses_to_stops;

    // остановка + маршруты, проходящие через неё, в порядке добавления
    map<string, vector<string>> stops_to_buses;
};
