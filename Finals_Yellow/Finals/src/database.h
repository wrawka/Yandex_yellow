/*
 * database.h
 *
 *  Created on: 13 февр. 2020 г.
 *      Author: A.Lebedev
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "Date.h"
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Database {
public:
	/*
	 * Встретив команду Add date event, ваша программа
	 * должна добавить пару (date, event) в базу данных
	 */
	void Add(){}

	/*
	 * Встретив команду Print, ваша программа должна вывести
	 * все пары (дата, событие), которые в данный момент
	 * содержатся в базе данных. Пары надо выводить по одной в строке.
	 * Они должны быть отсортированы по дате по возрастанию.
	 * События в рамках одной даты необходимо выводить в порядке добавления
	 * (за исключением уже удалённых и попыток добавления повторов).
	 */
	  void Print() const {
	    for (const auto& item : storage) {
	      for (const string& event : item.second) {
	        cout << item.first << " " << event << endl;
	      }
	    }
	  }
	/*
	 * По команде Last date нужно вывести
	 * последнее из событий, случившихся к дате date.
	 */
	void Last(){}

	/*
	 * Встретив команду Find condition, ваша программа
	 * должна вывести все пары (дата, событие),
	 * которые в данный момент содержатся в базе данных
	 * и удовлетворяют условию condition.
	 */
	void FindIf(){}

	/*
	 * Встретив команду Del condition, ваша программа должна удалить
	 * из базы данных все события, удовлетворяющие условию condition
	 */
	void RemoveIf(){}

private:
	map<Date, set<string>> storage;
};



#endif /* DATABASE_H_ */
