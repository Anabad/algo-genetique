/*
 * ArrayUtils.h
 *
 *  Created on: Jan 29, 2017
 *      Author: anand
 */

#ifndef ARRAYUTILS_H_
#define ARRAYUTILS_H_

void copyArray(int* src,int size,int* dest);
void removeFromArray(int* src, int size, int index);
int findInArray(int* array, int size, int value);
void addToArray(int* array, int size, int value);
void initArray(int* array, int size);

#endif /* ARRAYUTILS_H_ */
