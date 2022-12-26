#include <iostream>
#include <cstdlib>
#include "vector.h"
#include "matrix.h"

int main()
{
	/*matr matrix1;
	matrix1.create_matr();
	matrix1.print_matr();

	vect a;
	a.create_vector();
	a.print_vect();

	vect c = mult(matrix1, a);
	c.print_vect();
	
	c.mult_double(2.0);
	c.print_vect();



	matr matrix2;
	matrix2 = matrix1;
	matrix2.print_matr();*/

    matr A;
    A.create_matr();
    int row = A.get_rows();
    int col = A.get_columns();

    vect b;
    b.create_vector();

    double** alpha_data = new double* [row];
    for (int i = 0; i < row; ++i)
    {
        alpha_data[i] = new double[col];
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (i != j)
            {
                alpha_data[i][j] = (-1) * A.get_matr()[i][j] / A.get_matr()[i][i];
            }
            else
            {
                alpha_data[i][j] = 0;
            }  
        }
    }
    matr alpha(row, col, alpha_data);

    double* betta_data = new double[row];
    for (int i = 0; i < row; ++i)
    {
        betta_data[i] = b.get_vect()[i] / A.get_matr()[i][i];
    }
    vect betta(row, betta_data);

    vect x_i = b;
    vect x_i1(row);

    double epsilon;

    std::cout << "Give an epsilon: ";
    std::cin >> epsilon;

    int iter = 0;
    while ((x_i1 - x_i).vector_norm() > epsilon)
    {
        x_i = x_i1;
        x_i1 = betta + mult(alpha, x_i);
        ++iter;
        std::cout << iter << " iteration result" << std::endl;
        x_i1.print_vect();
        if ((x_i1 - x_i).vector_norm() <= epsilon)
        {
            std::cout << "Final result ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < row; ++i)
    {
        delete[] alpha_data[i];
    }
    delete[] alpha_data;
    
    delete[] betta_data;
    //std::cout << "I'm heere! " << std::endl;
    return 0;
}
