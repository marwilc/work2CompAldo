/*
 * ejercicio3.cpp
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
	return(pow(x,3.0) - 5.0*pow(x,2.0) + 3.0*x - 7.0);
}

double gX(double x)
{
	return((functionX(x + functionX(x)) - functionX(x)) / functionX(x));
}


double functionPrimaX(double x)
{
	return(3.0*pow(x,2.0) - 10.0*x + 3.0);
}
int main() {


	int n;
	double x = 0e0;
	double epsilon = 1e-9;
	double tInit;
	double tNext = 0e0;


		tInit = 2;
		cout << endl<< setiosflags(ios:: left)
			 << setw(4) << "Xi"
			 << setw(20) << "X"
			 << setw(20) << "F(x)"
			 << setw(20) << "G(x)"
			 << endl;

		n = 0;
		x = functionX(tInit);
		while(abs(x) > epsilon){

			cout << setprecision(9)<< fixed << left
				 << setw(4)  << n
				 << setw(20) << tInit
				 << setw(20) << functionX(tInit)
				 << setw(20) << gX(tInit)
				 << endl;

			tNext = tInit - (x / gX(tInit));
			x = functionX(tNext);
			tInit = tNext;
			n++;

		}
		cout << setprecision(9)<< fixed << left
			 << setw(4)  << n
			 << setw(20) << tInit
		     << setw(20) << functionX(tInit)
			 << setw(20) << gX(tInit)
			 << endl;

	return 0;
}
