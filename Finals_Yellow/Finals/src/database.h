/*
 * database.h
 *
 *  Created on: 13 февр. 2020 г.
 *      Author: A.Lebedev
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <map>
#include <set>

#include "node.h"
#include "date.h"
using namespace std;

class Database {
public:
	void Add(const Date& date, const string& event);
	/*
	 * Встретив команду Add date event, ваша программа
	 * должна добавить пару (date, event) в базу данных
	 */

	  void Print(ostream& os) const;
	/*
	 * Встретив команду Print, ваша программа должна вывести
	 * все пары (дата, событие), которые в данный момент
	 * содержатся в базе данных. Пары надо выводить по одной в строке.
	 * Они должны быть отсортированы по дате по возрастанию.
	 * События в рамках одной даты необходимо выводить в порядке добавления
	 * (за исключением уже удалённых и попыток добавления повторов).
	 */

	ostream& Last(Date& date);
	/*
	 * По команде Last date нужно вывести
	 * последнее из событий, случившихся к дате date.
	 */

	void FindIf(Node& predicate);
	/*
	 * Встретив команду Find condition, ваша программа
	 * должна вывести все пары (дата, событие),
	 * которые в данный момент содержатся в базе данных
	 * и удовлетворяют условию condition.
	 */

	int RemoveIf(Node& predicate);
	/*
	 * Встретив команду Del condition, ваша программа должна удалить
	 * из базы данных все события, удовлетворяющие условию condition
	 */

private:
	map<Date, set<string>> storage;
};



#endif /* DATABASE_H_ */
