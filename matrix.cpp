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

matr::matr(int rows, int columns, double** data)
{
	this->rows = rows;
	this->columns = columns;
	this->data = data;
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

/*vect& vect::operator=(const vect& a)
{
	if (this != &a)
	{
		for (int i = 0; i < a.size; ++i)
		{
			this->data[i] = a.data[i];
		}
		this->size = a.size;
	}
	return *this;
}


vect operator+(const vect& a, const vect& b) {

	if (a.size != b.size) {
		std::cout << "Vectors should be the same dimension";
		exit(0);
	}
	double* data_result = new double[a.size];

	for (int i = 0; i < a.size; ++i) {
		data_result[i] = a.data[i] + b.data[i];
	}

	return vect(a.size, data_result);
}

vect operator-(const vect& a, const vect& b) {

	if (a.size != b.size) {
		std::cout << "Vectors should be the same dimension";
		exit(0);
	}
	double* data_result = new double[a.size];

	for (int i = 0; i < a.size; ++i) {
		data_result[i] = a.data[i] - b.data[i];
	}

	return vect(a.size, data_result);
}*/