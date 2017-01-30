/*
 * Chromosome.h
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include<sstream>
#include <cstdlib>
#include <iostream>
#include "structs.h"
#include "ArrayUtils.h"

using namespace std;

class Chromosome {
public:
	int* genome;
	int genomeSize;
	int distance;
	Chromosome();
	Chromosome(int genomeSize);
	Chromosome(int genomeSize,int* nodes);
	virtual ~Chromosome();
	string toString();
	void calculateDistance(struct edge* edges,int size);
	void mutate(int mutationProbability);
	static void insertSorted(Chromosome** array, int size, Chromosome* value);
	static int calculateAverage(Chromosome** array,int size);
	static void sort(Chromosome** array, int size);
};

#endif /* CHROMOSOME_H_ */
