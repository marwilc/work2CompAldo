//============================================================================
// Name        : ejercicio1.cpp
// Author      : Marwil Campos ci 21484386
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double functionX(double x)
{
	return(1.0 - (exp((-27.5  + 32.0*x - 8.0*pow(x,2.0))/9.0))
		     - (exp((-92.25 + 43.0*x - 5.0*pow(x,2.0))/6.0)));
}

double functionPrimaX(double x)
{
	return( (-(exp((-27.5  + 32.0*x - 8.0*pow(x,2.0))/9.0))/9.0 * (32.0 - 16.0*x)) +
		    (-(exp((-92.25 + 43.0*x - 5.0*pow(x,2.0))/6.0))/6.0 * (43.0 - 10.0*x)));
}
int main() {

	double vectorT[6] = {1.85, 2.0, 2.1, 2.15, 2.2 , 2.25};
	int n;
	double x = 0e0;
	double epsilon = 1e-9;
	double tInit;
	double tNext = 0e0;

	for (int i = 0; i <= 5; i++)
	{

		tInit = vectorT[i];
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
	}
	return 0;
}
