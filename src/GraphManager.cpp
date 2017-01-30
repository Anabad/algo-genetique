/*
 * GraphManager.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#include "GraphManager.h"

GraphManager::GraphManager() {
	this->nodes = new int[2];
	this->edges = new struct edge[1];
}

GraphManager::~GraphManager() {
	// TODO Auto-generated destructor stub
}

GraphManager::GraphManager(int numberOfNodes){
	this->numberOfNodes = numberOfNodes;
	this->numberOfEdges = (numberOfNodes-1)*(numberOfNodes)/2;
	int iterator = 0;
	this->nodes = new int[numberOfNodes];
	this->edges = new struct edge[this->numberOfEdges];
	struct edge newEdge;
	for (int i = 0; i < this->numberOfNodes; i++){
		this->nodes[i] = i;
	}
	for (int i = 0; i < this->numberOfNodes; i++){
		for (int j = i+1; j < this->numberOfNodes; j++){
			newEdge = {this->nodes[i],this->nodes[j],rand()%100};
			this->edges[iterator++] = newEdge;
		}
	}
}

string GraphManager::toString(){
	ostringstream output;
	output << "Graph has " << this->numberOfNodes;
	output << " nodes and " << this->numberOfEdges << " edges\n\n";
	output << "List of nodes:\n\n";
	for (int i = 0; i < numberOfNodes; i++){
		output << this->nodes[i] << " | ";
	}
	output << "\n\nList of distances between nodes:\n\n";
	for (int i = 0; i < this->numberOfEdges; i++){
		output << "Distance between node " << this->edges[i].node1;
		output << " and node " << this->edges[i].node2;
		output << " is " << this->edges[i].distance << "\n";
	}
	return output.str();
}
