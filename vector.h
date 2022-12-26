#pragma once 
#include <iostream>
#include "matrix.h"

class matr;

class vect
{
public:
	vect();
	vect(int size);
	vect(int size, double* data);
	~vect();
	void print_vect();
	double* get_vect();
	int get_size();
	void set_vect(int size, double* data);

	friend class matr;
	friend vect operator+(const vect& a, const vect& b);
	friend vect operator-(const vect& a, const vect& b);
	vect& operator = (const vect& a);
	friend vect mult(matr& a, vect& b);
private:
	int size;
	double* data;
};
