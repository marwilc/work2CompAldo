/*
 * ejercicio2.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: marwilc
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double functionX(double x)
{
	return(pow(x,3.0) + 94.0*pow(x,2.0) - 389.0*x + 294.0);
}

double functionPrimaX(double x)
{
	return(3.0*pow(x,2.0) + 188.0*x - 389.0);
}
int main()
{
		int n;
		double x = 0e0;
		double epsilon = 1e-9;
		double tInit;
		double tNext = 0e0;

			tInit = 5.1;
			cout << endl<< setiosflags(ios:: left)
				 << setw(4) << "Xi"
				 << setw(20) << "X"
				 << setw(20) << "F(x)"
				 << setw(20) << "F'(x)"
				 << endl;

			n = 0;
			x = functionX(tInit);
			while(abs(x) > epsilon){

				cout << setprecision(9)<< fixed << left
					 << setw(4)  << n
					 << setw(20) << tInit
					 << setw(20) << functionX(tInit)
					 << setw(20) << functionPrimaX(tInit)
					 << endl;

				tNext = tInit - (x / functionPrimaX(tInit));
				x = functionX(tNext);
				tInit = tNext;
				n++;

			}
			cout << setprecision(9)<< fixed << left
				 << setw(4)  << n
				 << setw(20) << tInit
			     << setw(20) << functionX(tInit)
				 << setw(20) << functionPrimaX(tInit)
				 << endl;

	return 0;
}


