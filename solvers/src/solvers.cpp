//============================================================================
// Name        : solvers.cpp
// Author      : Ivan Batistic
// Version     : 1.0
// Copyright   : /
// Description : Direct and iterative matrix solvers
//============================================================================

#include <iostream>
#include "matrix.h"
#include "gaussElimination.h"
using namespace std;

int main() {

	// matrix from Sanja Singer course mat4
	matrix A(4);
	A(0,0) =  1; A(0,1) = -2; A(0,2) = -1; A(0,3) =  0;
	A(1,0) = -6; A(1,1) =  0; A(1,2) =  1; A(1,3) =  1;
	A(2,0) =  1; A(2,1) =  6; A(2,2) =  0; A(2,3) = -4;
	A(3,0) =  2; A(3,1) = -1; A(3,2) =  1; A(3,3) =  1;

	vector<double> b = {1,1,0,0};

	gaussElimination solve(A,b);
	solve.time();
	solve.printSolution();


	return 0;
}
