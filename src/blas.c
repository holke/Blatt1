#include "blas.h"

// method to compute \vec{y} = \alpha \vec{x} + \vec{y}
void axpy(REAL alpha, REAL* x, REAL* y, int len)
{
	for (int i=0;i<len;i++)
	{
		y[i]=alpha*x[i]+y[i];
	}
}

REAL dot(REAL* x, REAL* y, int len)
{
	REAL result=0.0;

	for (int i=0;i<len;i++)
	{
		result+=x[i]*y[i];
	}

	return result;
}

REAL nrm2(REAL* x, int len)
{
	return sqrt(dot(x,x,len));
}

void copy(REAL* x, REAL* y, int len)
{
	for (int i=0;i<len;i++)
	{
		y[i]=x[i];
	}
}

void scal(REAL alpha, REAL* x, int len)
{
	for (int i=0;i<len;i++)
	{
		x[i]*=alpha;
	}
}

void gemv(REAL alpha, REAL** A, REAL* x, REAL beta, REAL* y, int rows, int cols)
{
	REAL sum;

	for (int i=0;i<rows;i++)
	{
		sum=0;
		for (int j=0;j<cols;j++)
		{
			sum+=A[i][j]*x[j];
		}

		y[i]=alpha*sum + beta*y[i];
	}
}

void scal2Dfield(REAL alpha, REAL** X, int sizeX, int sizeY)
{
	for (int i=0;i<sizeX;i++)
		for (int j=0;j<sizeY;j++)
			X[i][j]*=alpha;
}

void axpy2Dfield(REAL alpha, REAL** X, REAL** Y, int sizeX, int sizeY)
{
	for (int i=0;i<sizeX;i++)
		for (int j=0;j<sizeY;j++)
			Y[i][j]=alpha*X[i][j]+Y[i][j];
}
