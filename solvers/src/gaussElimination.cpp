/*
 * gaussElimination.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: ivan
 */

#include "gaussElimination.h"

// Constructor
gaussElimination::gaussElimination(matrix A, vector<double> b)
 : A_(A), b_(b), x_(b_.size(),0.0)
{
	solve();
}

gaussElimination::~gaussElimination(){}

void gaussElimination::solve()
{
	clock_t t1 = clock();
	const int& m = A_.size();

	for (int k=0; k<(m-1); k++)
	{
		for (int i=k+1; i<m; i++)
		{
			double ratio = A_(i,k)/ A_(k,k);

			for (int j=k+1; j<m; j++)
			{
				A_(i,j) = A_(i,j) - ratio*A_(k,j);
			}
			b_[i] = b_[i] - ratio*b_[k];
		}
	}
	clock_t t2 = clock();
	time_ = (t2 - t1) / double(CLOCKS_PER_SEC);

	for (int i=(m-1); i>=0; --i)
	{
		double a(0.0);
		for (int j=(m-1); j>i; --j)
		{
			a -= A_(i,j)*x_[j];
		}
		a = (a + b_[i]) * (1/A_(i,i));
		x_[i] = a;
	}
}

void gaussElimination::printSolution() const
{
	for (vector<double>::const_iterator i = x_.begin(); i != x_.end(); ++i)
	    cout << *i << endl;
	cout << endl;
}

void gaussElimination::time() const
{
	cout << "Solving time for gaussElimination: "
		 << fixed << time_ << " sek\n" << endl;
}

