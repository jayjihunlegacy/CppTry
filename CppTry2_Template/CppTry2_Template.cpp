#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
inline const T& mymax(const T& a, const T& b)
{
	return  a > b ? a : b;
}


int main()
{
	printf("%d\n", mymax<int>(2, 3));//mymax<int>()
	printf("%d", mymax(2, 3));//parameter inference : no explicit template!!
}