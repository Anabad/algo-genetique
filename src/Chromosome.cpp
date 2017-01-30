/*
 * Chromosome.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#include "Chromosome.h"
#include <iterator>

Chromosome::Chromosome(){

}

Chromosome::Chromosome(int genomeSize){
	this->genomeSize = genomeSize;
	this->distance = 0;
	this->genome = new int[genomeSize];
	initArray(this->genome,this->genomeSize);
}

Chromosome::Chromosome(int genomeSize,int* nodes) {
	this->genomeSize = genomeSize;
	this->genome = new int[genomeSize];
	this->distance = 0;
	int* unusedGenes = new int[genomeSize];
	copyArray(nodes, genomeSize, unusedGenes);
	for (int i=0; i < this->genomeSize; i++){
		int selectedGene = rand() % (genomeSize - i);
		this->genome[i] = unusedGenes[selectedGene];
		removeFromArray(unusedGenes, genomeSize - i, selectedGene);
	}
}

Chromosome::~Chromosome() {
	// TODO Auto-generated destructor stub
}

void Chromosome::calculateDistance(struct edge* edges, int size){
	this->distance = 0;
	for (int i = 0; i < this->genomeSize-1; i++){
		for (int j = 0; j < size; j++){
			if ((genome[i] == edges[j].node1 && genome[i+1] == edges[j].node2)
					|| (genome[i] == edges[j].node2 && genome[i+1] == edges[j].node1)){
				this->distance += edges[j].distance;
				break;
			}
		}
	}
}

void Chromosome::mutate(int mutationProbability){
	int temp;
	int switchIndex;
	for (int i = 0; i < this->genomeSize; i++){
		if(rand() % mutationProbability == 0){
			temp = this->genome[i];
			switchIndex = rand() % genomeSize;
			this->genome[i] = this->genome[switchIndex];
			this->genome[switchIndex] = temp;
		}
	}
}

string Chromosome::toString(){
	ostringstream output;
	for (int i = 0; i < genomeSize; i++){
		output << genome[i] << " | ";
	}
	output << "\n\n";
	return output.str();
}

void Chromosome::insertSorted(Chromosome** array, int size, Chromosome* value){
	Chromosome* temp;
	Chromosome* previous;
	for (int i = 0; i< size;i++){
		if(value->distance < array[i]->distance){
			previous = array[i];
			array[i] = value;
			for (int j = i+1; j < size; j++){
				temp = array[j];
				array[j] = previous;
				previous = temp;
			}
			break;
		}
	}
}

int Chromosome::calculateAverage(Chromosome** array, int size){
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += array[i]->distance;
	}
	return sum/size;
}

void Chromosome::sort(Chromosome** array, int size){
	bool flag = true;
	Chromosome* temp;
	for (int i = 1; i < size && flag; i++){
		flag = false;
		for (int j = 0; j < size-1;j++){
			if (array[j+1]->distance < array[j]->distance){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = true;
			}
		}
	}
}
