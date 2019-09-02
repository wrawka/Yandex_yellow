#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string query;
	is >> query;
	if (query == "NEW_BUS") {
		q.type = QueryType::NewBus;
		int stops_count;
		is >> q.bus >> stops_count;
		while (stops_count--) {
			string t_stop;
			is >> t_stop;
			q.stops.push_back(t_stop);
		}
	} else if (query == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (query == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (query == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
    return is;
}

struct BusesForStopResponse {
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.stop == "No stop\n") {
        os << r.stop;
    } else {
        for (const auto& out : r.buses) {
            os << out << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.bus == "No bus\n") {
        os << r.bus;
    } else {
    	for (const auto& out : r.stops) {
    		os << out << endl;
    	}
    }
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
	    buses_to_stops[bus] = stops;
	    for (auto& stop : stops) {
	    	stops_to_buses[stop].push_back(bus);
	    }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse response;
        response.stop = "";
        if (stops_to_buses.count(stop) == 0) {
        	response.stop = "No stop\n";
        } else {
        	response.buses = buses_to_stops.at(stop);
        }
        return response;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
    	StopsForBusResponse response;
    	response.bus = "";
    	int n = 0;
        if (buses_to_stops.count(bus) == 0) {
        	response.bus = "No bus\n";
        } else {
            for (const string& stop : buses_to_stops.at(bus)) {
            	string& some_stop = response.stops[n];
            	some_stop = "Stop " + stop + ": ";
            	if (stops_to_buses.at(stop).size() == 1) {
            		some_stop += "no interchange";
            	} else {
            		for (const string& other_bus : stops_to_buses.at(stop)) {
            			if (bus != other_bus) {
            				some_stop += other_bus + " ";
            			}
            		}
            	}
            	n++;
            }
        }
    	return response;
    }

//    AllBusesResponse GetAllBuses() const {
//        // Реализуйте этот метод
//    }
private:

    // маршрут + его остановки, в порядке добавления
    map<string, vector<string>> buses_to_stops;

    // остановка + маршруты, проходящие через неё, в порядке добавления
    map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
//        case QueryType::AllBuses:
//            cout << bm.GetAllBuses() << endl;
//            break;
        }
    }

    return 0;
}
