/*
 * node.h
 *
 *  Created on: 23 мар. 2020 г.
 *      Author: A.Lebedev
 */

#ifndef NODE_H_
#define NODE_H_

enum class Comparison {
	Less,				// "<"
	LessOrEqual,		// "<="
	Greater,			// ">"
	GreaterOrEqual,		// ">="
	Equal,				// "=="
	NotEqual,			// "!="
};

enum class LogicalOperation {
	And,				// "AND"
	Or,					// "OR"
};

class Node {
public:
	Node();
	~Node();

private:

};

class EmptyNode : public Node {

};

class DateComparisonNode : public Node {

};

class EventComparisonNode : public Node {

};

class LogicalOperationNode : public Node {

};


#endif /* NODE_H_ */
