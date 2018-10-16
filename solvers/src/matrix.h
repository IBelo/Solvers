/*
 * matrix.h
 *
 *  Created on: Oct 16, 2018
 *      Author: ivan
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

class matrix {
private:
    unsigned int size_;
    double **p;

    void allocSpace();

public:
    matrix(){};
	matrix(int);
    matrix(const matrix&);
	virtual ~matrix();
    inline double& operator()(int x, int y) { return p[x][y]; }
    unsigned int size() const {return size_; }
    void print() const;

};

#endif /* MATRIX_H_ */
