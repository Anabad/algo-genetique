//============================================================================
// Name        : algo-genetique.cpp
// Author      : Anand Badrinath
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Chromosome.h"
#include "GraphManager.h"
#include "Darwin.h"

using namespace std;

int main() {
	Darwin* darwin = new Darwin(100,20,100);
	cout << darwin->graphManager->toString() << endl;
	darwin->naturalSelection();
	return 0;
}
