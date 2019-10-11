#include "query.h"

istream& operator >> (istream& is, Query& q) {
	string query;
	is >> query;
	if (query == "NEW_BUS") {
		q.type = QueryType::NewBus;
		q.stops.clear();
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
