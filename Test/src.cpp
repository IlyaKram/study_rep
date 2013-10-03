/*
 * src.cpp
 *
 *  Created on: Sep 23, 2013
 *      Author: root
 */

#include <stdio.h>
#include "Rational.h"

int main(void)
{
	Rational Rat1(15, 25);
	Rational Rat2(3, 4);
	Rational Rat3 = Rat2 + Rat1;
	double dDouble = (double)Rat3;
	Rat2.Print();
	printf( "\n %lf \n" , dDouble );
	//printf( " ( " );
	//Rat2.Print();
	//printf( " ) = ");

	Rational Rat4 = Rat2 * Rat1;

	//Rational Deg = Rat2 ^ 2 ;
	Rat4.Print();

    return 0;
}


