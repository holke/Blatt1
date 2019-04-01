#ifndef BLAS_H_
#define BLAS_H_

#include <math.h>
#include "real.h"

void	axpy(REAL alpha, REAL* x, REAL* y, int len);
REAL	dot(REAL* x, REAL* y, int len);
REAL	nrm2(REAL* x, int len);
void	copy(REAL* x, REAL* y, int len);
void	scal(REAL alpha, REAL* x, int len);

void	gemv(REAL alpha, REAL** A, REAL* x, REAL beta, REAL* y, int rows, int cols);

void	scal2Dfield(REAL alpha, REAL** X, int sizeX, int sizeY);
void	axpy2Dfield(REAL alpha, REAL** X, REAL** Y, int sizeX, int sizeY);
#endif /* BLAS_H_ */
