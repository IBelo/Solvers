/*
 * gaussElimination.h
 *
 *  Created on: Oct 16, 2018
 *      Author: ivan
 */

#ifndef GAUSSELIMINATION_H_
#define GAUSSELIMINATION_H_

#include <iostream>
#include <ctime>
#include "matrix.h"
#include <vector>
using namespace std;

class gaussElimination {
private:
	matrix A_;
	vector<double> b_;
	vector<double> x_;
	void solve();
	double time_;

public:
	gaussElimination(matrix, vector<double>);
	virtual ~gaussElimination();
	void time() const;
	void printSolution() const;
};

#endif /* GAUSSELIMINATION_H_ */
