/*
 * Darwin.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#include "Darwin.h"

Darwin::Darwin(int numberOfChromosomes,int numberOfNodes,int numberOfIterations) {
	this->graphManager = new GraphManager(numberOfNodes);
	this->numberOfIterations = numberOfIterations;
	this->numberOfChromosomes = numberOfChromosomes;
	this->chromosomes = new Chromosome*[numberOfChromosomes];
	for (int i = 0; i < this->numberOfChromosomes; i++){
		this->chromosomes[i] = new Chromosome(numberOfNodes,graphManager->nodes);
		this->chromosomes[i]->calculateDistance(graphManager->edges, graphManager->numberOfEdges);
	}
	Chromosome::sort(this->chromosomes,this->numberOfChromosomes);
	this->average = Chromosome::calculateAverage(chromosomes,numberOfChromosomes);
	this->best = chromosomes[0]->distance;
//	for (int i = 0; i < 5; i++){
//		cout << "Chromosome " << i << ": " << chromosomes[i]->toString() << endl;
//	}
}

Darwin::~Darwin() {
	// TODO Auto-generated destructor stub
}

Chromosome* Darwin::cross(Chromosome* chromosome1, Chromosome* chromosome2){
	Chromosome* newChromosome = new Chromosome(chromosome1->genomeSize);
	int* queue = new int[chromosome1->genomeSize];
	initArray(queue,newChromosome->genomeSize);
	int indexInQueue;
	for(int i = 0; i < newChromosome->genomeSize; i++){
		if(i%2 == 0){
			if(findInArray(newChromosome->genome,
					newChromosome->genomeSize,
					chromosome1->genome[i]) == -1){

				newChromosome->genome[i] = chromosome1->genome[i];

				indexInQueue = findInArray(queue,newChromosome->genomeSize,chromosome1->genome[i]);

				if (indexInQueue != -1){
					removeFromArray(queue, newChromosome->genomeSize, indexInQueue);
				}
				if (findInArray(queue,
						newChromosome->genomeSize,
						chromosome2->genome[i]) == -1
						&&
						findInArray(newChromosome->genome,
						newChromosome->genomeSize,
						chromosome2->genome[i]) == -1){

					addToArray(queue, newChromosome->genomeSize, chromosome2->genome[i]);
				}
			}
			else{
				newChromosome->genome[i] = queue[0];
				removeFromArray(queue, newChromosome->genomeSize, 0);
				if (findInArray(queue,
						newChromosome->genomeSize,
						chromosome2->genome[i]) == -1
						&&
						findInArray(newChromosome->genome,
						newChromosome->genomeSize,
						chromosome2->genome[i]) == -1){

					addToArray(queue, newChromosome->genomeSize, chromosome2->genome[i]);
				}
			}
		}
		else {
			if(findInArray(newChromosome->genome,
								newChromosome->genomeSize,
								chromosome2->genome[i]) == -1){

							newChromosome->genome[i] = chromosome2->genome[i];

							indexInQueue = findInArray(queue,newChromosome->genomeSize,chromosome2->genome[i]);

							if (indexInQueue != -1){
								removeFromArray(queue, newChromosome->genomeSize, indexInQueue);
							}

							if (findInArray(queue,
									newChromosome->genomeSize,
									chromosome1->genome[i]) == -1
									&&
									findInArray(newChromosome->genome,
									newChromosome->genomeSize,
									chromosome1->genome[i]) == -1){

								addToArray(queue, newChromosome->genomeSize, chromosome1->genome[i]);
							}
						}
						else{
							newChromosome->genome[i] = queue[0];
							removeFromArray(queue, newChromosome->genomeSize, 0);
							if (findInArray(queue,
									newChromosome->genomeSize,
									chromosome1->genome[i]) == -1
									&&
									findInArray(newChromosome->genome,
									newChromosome->genomeSize,
									chromosome1->genome[i]) == -1){

								addToArray(queue, newChromosome->genomeSize, chromosome1->genome[i]);
							}
						}
		}
//		cout << "Cross iteration " << i << "\n\n";
//		for (int j = 0; j < newChromosome->genomeSize; j++){
//			cout << newChromosome->genome[j] << " | " << queue[j] << endl;
//		}
	}
//	if (findInArray(newChromosome->genome, newChromosome->genomeSize, -1) != -1){
//		cout << "c1: " << chromosome1->toString();
//		cout << "c2: " << chromosome2->toString();
//	}
	return newChromosome;
}

void Darwin::naturalSelection(){
	Chromosome** newChromosomes = new Chromosome*[this->numberOfChromosomes/2];
	int newChromosomesIndex = 0;
	for (int i = 0; i < numberOfIterations; i++){
		for (int j = 0; j < numberOfChromosomes; j++){
			for (int k = j+1; k < numberOfChromosomes;k++){
				if (newChromosomesIndex < this->numberOfChromosomes/2){
					Chromosome* newChromosome = cross(chromosomes[j],chromosomes[k]);
					if (findInArray(newChromosome->genome, newChromosome->genomeSize, -1) != -1){
						cout << "Offending chromosome:\n\n";
						cout << newChromosome->toString();
						return;
					}
					newChromosome->mutate(1000);
					newChromosome->calculateDistance(graphManager->edges, graphManager->numberOfEdges);
					newChromosomes[newChromosomesIndex++] = newChromosome;
				}
				else{
					Chromosome* newChromosome = cross(chromosomes[j],chromosomes[k]);
					newChromosome->mutate(1000);
					newChromosome->calculateDistance(graphManager->edges, graphManager->numberOfEdges);
					Chromosome::insertSorted(newChromosomes, numberOfChromosomes/2, newChromosome);
				}
			}
		}
		for (int j = 0; j < numberOfChromosomes/2; j++){
			Chromosome::insertSorted(chromosomes, numberOfChromosomes, newChromosomes[j]);
		}
		this->average = Chromosome::calculateAverage(chromosomes,numberOfChromosomes);
		this->best = chromosomes[0]->distance;
//		cout << "Best population:\n\n";
//		for (int i = 0; i < 5; i++){
//			cout << "Distance " << i << ": " << chromosomes[i]->distance << endl;
//		}
		cout << "Iteration: " << i << "\n\n";
		cout << "Population average: " << this->average << "\n\n";
		cout << "Population best :"<<this->chromosomes[0]->distance<<"\n\n" << this->chromosomes[0]->toString();
	}
}

