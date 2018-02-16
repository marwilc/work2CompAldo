/*
 * ejercicio4.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: marwilc
 */




#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double epsilon= 1e-9;

double functionX(double x)
{
	return(2.0*pow(x,3.0) -  (34.0/7.0) * pow(x,2.0) + (209.0/49.0) * x - (173.0/343.0));
}


void secante(double p0, double p1)
{

	double q0 = functionX(p0);
	double q1 = functionX(p1);
	double p;
	int n=2;

	cout << setprecision(9) << fixed << setiosflags(ios:: left)
		 << setw(4)  << "i"
		 << setw(20) << "p0"
		 << setw(20) << "p1"
		 << setw(20) << "q0"
		 << setw(20) << "q1"
		 << setw(20) << "p"
		 << endl;

	p = p1 - q1*(p1 - p0)/(q1 - q0);
	while(abs(p - p1) > epsilon )
	{
		cout << setw(4)  << n
			 << setw(20) << p0
			 << setw(20) << p1
		     << setw(20) << q0
		     << setw(20) << q1
			 << setw(20) << p
			 << endl;

		p0= p1;
		q0=q1;
		p1=p;
		q1=functionX(p);

		p = p1 - q1*(p1 - p0)/(q1 - q0);
		n++;
	}

	cout << setw(4)  << n
		 << setw(20) << p0
		 << setw(20) << p1
	     << setw(20) << q0
		 << setw(20) << q1
	     << setw(20) << p
		 << endl;
}

void falsaPosicion(double p0, double p1 )
{
	int n=2;
	double p;
	double q;
	double q0=functionX(p0);
	double q1=functionX(p1);



	cout << setprecision(9) << fixed << setiosflags(ios:: left)
		 << setw(4)  << "i"
		 << setw(20) << "p0"
		 << setw(20) << "p1"
		 << setw(20) << "q0"
		 << setw(20) << "q1"
		 << setw(20) << "p"
		 << endl;

	p = (p1 - q1*(p1 -p0)/ (q1 -q0));;
	while(abs(p - p1) > epsilon)
	{
		cout << setw(4) << n
			 << setw(20) << p0
			 << setw(20) << p1
			 << setw(20) << q0
			 << setw(20) << q1
			 << setw(20) << p
			 << endl;

		n++;
		q=functionX(p);

		if(q*q1 < 0)
		{
			p0=p1;
			q0=q1;
		}
		p1=p;
		q1=q;

		p = (p1 - q1*(p1 -p0)/ (q1 -q0));
	}
	cout << setw(4) << n
		 << setw(20) << p0
		 << setw(20) << p1
		 << setw(20) << q0
		 << setw(20) << q1
		 << setw(20) << p
		 << endl;

}


int main()
{
	falsaPosicion(-1.00, 1.00);
	cout << endl;
	secante(-1.00,1.00);
	return 0;
}
