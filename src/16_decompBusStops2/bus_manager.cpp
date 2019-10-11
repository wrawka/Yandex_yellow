#include "bus_manager.h"

using namespace std;

    void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	    buses_to_stops[bus] = stops;
	    for (auto& stop : stops) {
	    	stops_to_buses[stop].push_back(bus);
	    }
    }

    BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
        BusesForStopResponse response;
        response.stop = "";
        if (stops_to_buses.count(stop) == 0) {
        	response.stop = "No stop\n";
        } else {
        	response.buses = stops_to_buses.at(stop);
        }
        return response;
    }

    StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    	StopsForBusResponse response;
    	response.bus = "";
    	response.stops.clear();
        if (buses_to_stops.count(bus) == 0) {
        	response.bus = "No bus\n";
        } else {
            for (const string& stop : buses_to_stops.at(bus)) {
            	string some_stop = "Stop " + stop + ": ";
            	if (stops_to_buses.at(stop).size() == 1) {
            		some_stop += "no interchange";
            	} else {
            		for (const string& other_bus : stops_to_buses.at(stop)) {
            			if (bus != other_bus) {
            				some_stop += other_bus + " ";
            			}
            		}
            	}
            	response.stops.push_back(some_stop);
            }
        }
    	return response;
    }

    AllBusesResponse BusManager::GetAllBuses() const {
    	AllBusesResponse response;
    	response.all_buses.clear();
        if (buses_to_stops.empty()) {
        	response.all_buses.push_back("No buses");
        } else {
        	for (const auto& bus_item : buses_to_stops) {
        		string bus_line = "Bus " + bus_item.first + ": ";
        		for (const string& stop : bus_item.second) {
        			bus_line += stop + " ";
        		}
        		response.all_buses.push_back(bus_line);
        	}
        }
    	return response;
    }
