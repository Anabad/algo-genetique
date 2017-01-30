/*
 * Darwin.h
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#ifndef DARWIN_H_
#define DARWIN_H_


#include "Chromosome.h"
#include "GraphManager.h"
#include "ArrayUtils.h"
#include <iostream>
#include <algorithm>

class Darwin {
public:
	Chromosome** chromosomes;
	int numberOfChromosomes;
	GraphManager* graphManager;
	int numberOfIterations;
	int average;
	int best;
	Darwin(int numberOfChromosomes,int numberOfNodes, int numberOfIterations);
	virtual ~Darwin();
	Chromosome* cross(Chromosome* chromosome1, Chromosome* chromosome2);
	void naturalSelection();
	void crossAll();
};

#endif /* DARWIN_H_ */
