#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int a = 100;
	int b = 50;

	//1. const with int : no meaningful position.
	const int c = 50;
	int const d = 100;
	//result is the same.

	//2. const with int*
	const int * e = &a;// var-pointer to const-int
	int const * f = &a;// var-pointer to const-int
	int * const g = &a;// const-pointer to var-int

	*e = 10;
	*f = 20;
	*g = 30;

	e = &b;
	f = &b;
	g = &b;
	//const int == int const != int * const

	//3. const with int **
	int * p1 = &a;
	int * const p2 = &a;
	// setting
	const int ** pp1 = &p1;// var-pointer to var-pointer to const-int
	int const ** pp2 = &p1;// var-pointer to var-pointer to const-int
	int * const *pp3 = &p1;// var-pointer to const-pointer to var-int
	int ** const pp4 = &p1;// const-pointer to var-pointer to var-int

	**pp1 = 10;//X
	**pp2 = 10;//X
	**pp3 = 10;//O
	**pp4 = 10;//O

	*pp1 = &b;//O
	*pp2 = &b;//O
	*pp3 = &b;//X
	*pp4 = &b;//O

	pp1 = &p1;//O
	pp2 = &p1;//O
	pp3 = &p1;//O
	pp4 = &p1;//X
}