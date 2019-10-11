#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct BusesForStopResponse {
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    vector<string> all_buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
