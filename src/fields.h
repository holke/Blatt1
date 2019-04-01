#ifndef FIELDS_H_
#define FIELDS_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "real.h"

REAL*	create1Dfield(int size);
REAL**	create2Dfield(int sizeX, int sizeY);
REAL*	createVector(int len);
REAL**	createMatrix(int rows, int cols);

void 	destroy1Dfield(REAL* field);
void 	destroy2Dfield(REAL** field, int sizeX);
void	destroyVector(REAL* vector);
void	destroyMatrix(REAL** matrix, int rows);

void	fill1Dfield(REAL value, REAL* field, int size);
void	fill2Dfield(REAL value, REAL** field, int sizeX, int sizeY);

int     isEqualScalar(REAL x, REAL y, REAL eps);
int 	isEqual1Dfield(REAL* field1, REAL* field2, int size, REAL eps);
int 	isEqual2Dfield(REAL** field1, REAL** field2, int sizeX, int sizeY,  REAL eps);

void	applyFunctionTo1Dfield(REAL (*func)(REAL), REAL* field, int size);
void	applyFunctionTo2Dfield(REAL (*func)(REAL), REAL** field, int sizeX, int sizeY);

void	print1Dfield(REAL* field, int size);
void	print2Dfield(REAL** field, int sizeX, int sizeY);
void	printVector(REAL* vector, int len);
void	printMatrix(REAL** matrix, int rows, int cols);

void	write1Dfield(const char* fileName, REAL* field, int size);
void	write2Dfield(const char* fileName, REAL** field, int sizeX, int sizeY);

REAL* 	read1Dfield(const char* fileName, int* size);
REAL**	read2Dfield(const char* fileName, int* sizeX, int* sizeY);

void	writeVTKfileFor2DscalarField(const char* fileName, const char* description, REAL** field, int sizeX, int sizeY, REAL dx, REAL dy);
void	writeVTKfileFor2DvectorField(const char* fileName, const char* description, REAL** fieldU, REAL** fieldV, int sizeX, int sizeY, REAL dx, REAL dy);


#endif /* FIELDS_H_ */
