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
        int stops;
        is >> q.bus >> stops;
        while (stops--) {
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
    if (r.stop == "No stop") {
        os << r.stop;
    } else {
        for (auto& out : r.buses) {
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
    if (r.bus == "No bus") {
        os << r.bus;
    } else {
        for (auto& out : r.stops) {
            os << out << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> all_routes;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        routes[bus] = stops;
        routes_history.push_back(bus);
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse response;
        response.stop = "";
        for (const auto& route : routes) {
            if (route.second.count(stop) != 0)
        }
        
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse response;
        response.all_routes = routes;
        return response;
    }
private:
    map<string, vector<string>> routes;
    vector<string> routes_history;
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
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}
