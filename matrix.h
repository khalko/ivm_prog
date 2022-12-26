#pragma once
#include "vector.h"
#include <iostream>

class matr
{
public:
	matr();
	matr(int rows, int columns);
	matr(int rows, int columns, double** data);
	~matr();
	void print_matr();
	double** get_matr();
	int get_rows();
	int get_columns();
	void set_matr(int rows, int columns, double** data);

	friend matr operator+(const matr& a, const matr& b);
	friend matr operator-(const matr& a, const matr& b);
	matr& operator = (const matr& a);
private:
	int columns;
	int rows;
	double** data;



};
