#include "responses.h"

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

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    for (const auto& out : r.all_buses) {
    	os << out << endl;
    }
    return os;
}
