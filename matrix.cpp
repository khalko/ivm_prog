#include "matrix.h"
#include <iostream>

matr::matr()
{
	rows = 0;
	columns = 0;
	data = nullptr;
}

matr::matr(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	data = new double* [rows];
	for (int i = 0; i < rows; ++i)
	{
		data[i] = new double[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			data[i][j] = 0;
		}
	}
}

matr::matr(int rows, int columns, double** new_data)
{
	this->rows = rows;
	this->columns = columns;
	data = new double* [rows];
	for (int i = 0; i < rows; ++i)
	{
		data[i] = new double[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			data[i][j] = new_data[i][j];
		}
	}
}

matr::~matr()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
}

void matr::print_matr()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double** matr::get_matr()
{
	return data;
}

int matr::get_rows()
{
	return rows;
}

int matr::get_columns()
{
	return columns;
}

void matr::set_matr(int rows, int columns, double** new_data)
{
	this->rows = rows;
	this->columns = columns;
	//=================== delete old data ==================
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	//=================== create new_data ==================
	for (int i = 0; i < rows; ++i)
	{
		data[i] = new double[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			data[i][j] = new_data[i][j];
		}
	}
}

void matr::create_matr()
{
	int a, b;
	std::cout << "Number of rows: ";
	std::cin >> a;
	std::cout << "Number of columns: ";
	std::cin >> b;
	//=================== delete old data ==================
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	//=================== create new data ==================
	rows = a;
	columns = b;
	data = new double* [rows];
	for (int i = 0; i < rows; ++i)
	{
		data[i] = new double[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << "Element " << "[" << i+1 << "]" << "[" << j+1 << "] ";
			std::cin >> data[i][j];
		}
	}
	std::cout << std::endl;
}

matr& matr::operator=(const matr& a)
{
	this->rows = a.rows;
	this->columns = a.columns;
	if (this != &a)
	{
	//=================== delete old data ==================
		if (data != nullptr)
		{
			for (int i = 0; i < rows; ++i)
			{
				delete[] data[i];
			}
			delete[] data;
		}
	//=================== create new data ==================
		data = new double* [rows];
		for (int i = 0; i < rows; ++i)
		{
			data[i] = new double[columns];
		}
		for (int i = 0; i < a.rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				data[i][j] = a.data[i][j];
			}
		}
	}
	return *this;
}


