#include <iostream>
#include <cstdlib>
#include "vector.h"
#include "matrix.h"

int main()
{
	int col = 3;
	int row = 3;
	double** matritsa = new double* [row];

	for (int i = 0; i < row; ++i)
	{
		matritsa[i] = new double[col];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cin >> matritsa[i][j];
		}
	}
	/*double* vector1 = new double[size1];
	double* vector2 = new double[size2];
	for (int i = 0; i < size1; ++i)
	{
		std::cout << "Give me " << i << " coordinate";
		std::cin >> vector1[i];
	}
	for (int i = 0; i < size2; ++i)
	{
		std::cout << "Give me " << i << " coordinate";
		std::cin >> vector2[i];
	}
	vect a(size1);
	vect b(size2);
	vect c(size1);
	a.set_vect(size1, vector1);
	b.set_vect(size2, vector2);

	c = a + b;
	a.print_vect();
	b.print_vect();
	c.print_vect();
	return 0;*/

	matr matras(row, col, matritsa);
	double* vector1 = new double[col];
	for (int i = 0; i < col; ++i)
	{
		std::cout << "Give me " << i << " coordinate";
		std::cin >> vector1[i];
	}
	vect a(col, vector1);
	vect c = mult(matras, a);
	matras.print_matr();
	c.print_vect();

	vect sum(row);
	sum = a + c;
	sum.print_vect();

}
