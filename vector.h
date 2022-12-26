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
	double vector_norm();
	
	friend class matr;
	friend vect operator+(const vect& a, const vect& b);
	friend vect operator-(const vect& a, const vect& b);
	vect& operator = (const vect& a);
	friend vect mult(matr& a, vect& b);
	void mult_double(double a);
	void create_vector();
private:
	int size;
	double* data;
};
