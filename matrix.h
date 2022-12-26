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
	void create_matr();
	double** get_matr();
	int get_rows();
	int get_columns();
	void set_matr(int rows, int columns, double** data);
	matr& operator = (const matr& a);
private:
	int columns;
	int rows;
	double** data;



};
