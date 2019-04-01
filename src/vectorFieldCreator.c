#include <stdlib.h>
#include <stdio.h>

#include "fields.h"
#include "blas.h"
#include "real.h"

#include <math.h>

int main(int argc, char* argv[])
{
	REAL** U = create2Dfield(60,60);
	REAL** V = create2Dfield(60,60);

	for (int i=0;i<60;i++)
	{
		for (int j=0;j<60;j++)
		{
			REAL u,v;
			u=(REAL)i * 0.1;
			v=(REAL)j * 0.1;

			u=u-3.0;
			v=v-3.0;

			REAL norm=sqrt(u*u+v*v);
			if (fabs(norm)>1e-15)
			{
				u/=norm*10.0;
				v/=norm*10.0;
			}

			if (norm<3.0)
			{
				U[i][j]=u;
				V[i][j]=v;
			}
			else
			{
				U[i][j]=0.0;
				V[i][j]=0.0;
			}
		}
	}

	write2Dfield("fieldU.dat", U, 60, 60);
	write2Dfield("fieldV.dat", V, 60, 60);


	destroy2Dfield(U,60);
	destroy2Dfield(V,60);

	return 0;
}
