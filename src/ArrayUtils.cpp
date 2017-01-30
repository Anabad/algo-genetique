/*
 * ArrayUtils.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#include "ArrayUtils.h"

void copyArray(int* src, int size, int* dest){
	for (int i = 0; i < size; i++){
		dest[i] = src[i];
	}
}

void removeFromArray(int* src, int size, int index){
	for(int i=index; i < size-1; i++){
		src[i] = src[i+1];
	}
	src[size-1] = -1;
}

int findInArray(int* array, int size, int value){
	for (int i = 0; i < size; i++){
		if (array[i] == value){
			return i;
		}
	}
	return -1;
}

void addToArray(int* array, int size, int value){
	for(int i = 0; i < size; i++){
		if(array[i] == -1){
			array[i] = value;
			return;
		}
	}
}

void initArray(int* array, int size){
	for(int i = 0; i < size; i++){
			array[i] = -1;
		}
}
