/*
 * graphManager.h
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#ifndef GRAPHMANAGER_H_
#define GRAPHMANAGER_H_

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "structs.h"

using namespace std;

class GraphManager {
public:
	int* nodes;
	struct edge* edges;
	int numberOfNodes;
	int numberOfEdges;
	GraphManager();
	GraphManager(int);
	virtual ~GraphManager();
	string toString();
};

#endif /* GRAPHMANAGER_H_ */
