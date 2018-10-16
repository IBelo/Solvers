/*
 * matrix.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: ivan
 */

#include "matrix.h"
#include <iomanip>

// Private member function

void matrix::allocSpace()
{
    p = new double*[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        p[i] = new double[size_];
    }
}

// Constructors

matrix::matrix(int size)
 : size_(size)
{
	allocSpace();

	for (unsigned int i(0); i<size_; i++)
	{
		for (unsigned int j(0); j<size_; j++)
		{
			p[i][j] = 0.0;
		}
	}
}
 // Copy constructor
matrix::matrix(const matrix& m) : size_(m.size_)
{
    allocSpace();
    for (unsigned int i = 0; i < size_; ++i)
    {
        for (unsigned int j = 0; j < size_; ++j)
        {
            p[i][j] = m.p[i][j];
        }
    }
}

// Destructors

matrix::~matrix() {
	for (unsigned int i = 0; i < size_; ++i)
	{
		delete[] p[i];
	}
	delete[] p;
}

// Public member function

void matrix::print() const
{
	for (unsigned int i(0); i<size_; i++)
	{
		for (unsigned int j(0); j<size_; j++)
		{
			cout << setw(10) << left << p[i][j] << flush;
		}
		cout << endl;
	}
}
